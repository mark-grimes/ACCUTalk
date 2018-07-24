/*
 * This file is from some code I wrote a while ago for a much larger project. Hence the namespaces
 * don't make much sense for the ACCU talk.
 *
 * Copyright 2018 Mark Grimes (mark.grimes@rymapt.com)
 * I haven't decided on a licence, if anybody particularly wants to use it I'll consider open
 * sourcing it.
 */
#include "NDimensionalBinner.h"
#include <catch.hpp>

//
// Unnamed namespace for things only used in this file
//
namespace
{
	/** @brief Subclass the item under test purely so that I can expose and run protected methods */
	template<typename T_bin,bool IncludeOverflow,typename T_axis,typename... T_otheraxes>
	class BinnerTester : public implbasic::impl::NDimensionalBinner<T_bin,IncludeOverflow,T_axis,T_otheraxes...>
	{
	public:
		typedef implbasic::impl::NDimensionalBinner<T_bin,IncludeOverflow,T_axis,T_otheraxes...> WrappedType;
		static constexpr typename WrappedType::axis_index_type UnderflowBin=WrappedType::UnderflowBin; ///< The index of the underflow bin
		static constexpr typename WrappedType::axis_index_type OverflowBin=WrappedType::OverflowBin; ///< The index of the overflow bin

		template<typename... T_otherargs>
		BinnerTester( unsigned int numberOfBins, const T_axis& lowerEdge, const T_axis& upperEdge, T_otherargs... otherArgs )
			: WrappedType(numberOfBins,lowerEdge,upperEdge,otherArgs...)
		{
		}
		template<typename... T_otherargs>
		BinnerTester( const std::vector<T_axis>& binEdges, T_otherargs... otherArgs )
			: WrappedType(binEdges,otherArgs...)
		{
		}
		template<typename... T_otherargs>
		BinnerTester( std::vector<T_axis>&& binEdges, T_otherargs... otherArgs )
			: WrappedType(std::forward<std::vector<T_axis> >(binEdges),otherArgs...)
		{
		}
		static constexpr size_t InvalidBinIndex=WrappedType::InvalidBinIndex;
		size_t coordToIndex( const T_axis& arg1, T_otheraxes... otherArgs ) const
		{
			return WrappedType::coordToIndex( arg1, otherArgs... );
		}
		template<typename... T_otherArgs>
		size_t binNumberToIndex( typename implbasic::impl::Axis<T_axis>::index_type axisBinNumber, T_otherArgs... otherBinNumbers ) const
		{
			return WrappedType::binNumberToIndex( axisBinNumber, otherBinNumbers... );
		}
		const std::vector<T_bin>& getBins_() const
		{
			return this->bins_;
		}
		void setBins( std::vector<T_bin>&& newValues ) // Force the bin contents for certain tests
		{
			if( newValues.size()!=this->bins_.size() ) throw std::runtime_error("Invalid number of bins");
			this->bins_.swap( newValues );
		}
		void setInvalid( const T_bin& newValue )
		{
			this->invalidEntry_=newValue;
		}
	};

	template<typename T_bin,bool IncludeOverflow,typename T_axis,typename... T_otheraxes>
	constexpr size_t BinnerTester<T_bin,IncludeOverflow,T_axis,T_otheraxes...>::InvalidBinIndex;
} // end of the unnamed namespace


SCENARIO( "Test that the NDimensionalBinner constructors create the correct number of bins", "[ImplBasic]" )
{
	WHEN( "Creating a one dimensional binner with fixed binning" )
	{
		::BinnerTester<double,true,double> testBinner( 3, -0.5, 2.5 );
		CHECK( testBinner.getBins_().size()==5 ); // Should have 3 bins plus under and overflow
	}
	WHEN( "Creating a two dimensional binner with fixed binning" )
	{
		::BinnerTester<double,true,double,double> testBinner( 3, -0.5, 2.5, 4, 13.5, 17.5 );
		CHECK( testBinner.getBins_().size()==30 ); // Should have (3+2)*(4+2) bins
	}
	WHEN( "Creating a three dimensional binner with fixed binning" )
	{
		::BinnerTester<double,true,double,double,double> testBinner( 3, -0.5, 2.5, 4, 13.5, 17.5, 2, 1.5, 3.5 );
		CHECK( testBinner.getBins_().size()==120 ); // Should have (3+2)*(4+2)*(2+2) bins
	}
	WHEN( "Creating a three dimensional binner with variable binning" )
	{
		std::vector<double> xBinEdges{ 0.4, 3, 5.6, 8.8 };
		std::vector<double> yBinEdges{ 12.4, 23.8, 99.0, 100, 102.4 };
		std::vector<double> zBinEdges{ 0.2, 12.2, 14.5 };
		::BinnerTester<double,true,double,double,double> testBinner( xBinEdges, yBinEdges, zBinEdges );
		CHECK( testBinner.getBins_().size()==120 ); // Should have (4-1+2)*(5-1+2)*(3-1+2) bins
	}
	//
	// Basically just repeat the tests above, but without under and overflow
	// so each dimension has two fewer bins.
	//
	WHEN( "Creating a one dimensional binner with fixed binning and no out-of-bounds" )
	{
		::BinnerTester<double,false,double> testBinner( 3, -0.5, 2.5 );
		CHECK( testBinner.getBins_().size()==3 ); // Should have 3 bins (no under or overflow)
	}
	WHEN( "Creating a two dimensional binner with fixed binning and no out-of-bounds" )
	{
		::BinnerTester<double,false,double,double> testBinner( 3, -0.5, 2.5, 4, 13.5, 17.5 );
		CHECK( testBinner.getBins_().size()==12 ); // Should have 3*4 bins
	}
	WHEN( "Creating a three dimensional binner with fixed binning and no out-of-bounds" )
	{
		::BinnerTester<double,false,double,double,double> testBinner( 3, -0.5, 2.5, 4, 13.5, 17.5, 2, 1.5, 3.5 );
		CHECK( testBinner.getBins_().size()==24 ); // Should have 3*4*2 bins
	}
	WHEN( "Creating a three dimensional binner with variable binning and no out-of-bounds" )
	{
		std::vector<double> xBinEdges{ 0.4, 3, 5.6, 8.8 };
		std::vector<double> yBinEdges{ 12.4, 23.8, 99.0, 100, 102.4 };
		std::vector<double> zBinEdges{ 0.2, 12.2, 14.5 };
		::BinnerTester<double,false,double,double,double> testBinner( xBinEdges, yBinEdges, zBinEdges );
		CHECK( testBinner.getBins_().size()==24 ); // Should have (4-1)*(5-1)*(3-1) bins
	}
	//
	// See if mixing the different constructor styles works
	//
	WHEN( "Creating a 3D binner with a mixture of variable and fixed binning" )
	{
		std::vector<double> yBinEdges{ 12.4, 23.8, 99.0, 100, 102.4 };
		::BinnerTester<double,true,double,double,double> testBinner( 3, -0.5, 2.5, yBinEdges, 2, 1.5, 3.5 );
		CHECK( testBinner.getBins_().size()==120 ); // Should have (3+2)*(4+2)*(2+2) bins
	}
}

SCENARIO( "Test that the NDimensionalBinner::coordToIndex protected method works as expected", "[ImplBasic]" )
{
	// These tests require knowledge of the array layout NDimensionalBinner uses. In theory
	// I guess I should change to just checking that the values returned are unique and in
	// range, but I can't be bothered. Currently these tests will fail if the array layout
	// changes internally (e.g. out-of-bounds bins moved to the start of the array).
	WHEN( "Testing a 1D binner" )
	{
		::BinnerTester<double,true,double> testBinner( 5, -0.5, 4.5 );
		CHECK( testBinner.coordToIndex(0)==0 );
		CHECK( testBinner.coordToIndex(1)==1 );
		CHECK( testBinner.coordToIndex(2)==2 );
		CHECK( testBinner.coordToIndex(3)==3 );
		CHECK( testBinner.coordToIndex(4)==4 );
		CHECK( testBinner.coordToIndex(-1)==5 ); // Underflow bin
		CHECK( testBinner.coordToIndex(-20.5)==5 );
		CHECK( testBinner.coordToIndex(-99999)==5 );
		CHECK( testBinner.coordToIndex(6)==6 ); // Overflow bin
		CHECK( testBinner.coordToIndex(7)==6 );
		CHECK( testBinner.coordToIndex(70)==6 );
		CHECK( testBinner.coordToIndex(99999)==6 );
		CHECK( testBinner.coordToIndex(std::numeric_limits<double>::quiet_NaN()) == (::BinnerTester<double,true,double>::InvalidBinIndex) );
		CHECK( testBinner.coordToIndex(-std::numeric_limits<double>::quiet_NaN()) == (::BinnerTester<double,true,double>::InvalidBinIndex) );
		CHECK( testBinner.getBins_().size()==7 );
	}
	WHEN( "Testing a 1D binner with no out-of-bounds" )
	{
		// Exactly the same test as before, except out of bounds values should give InvalidBinIndex
		::BinnerTester<double,false,double> testBinner( 5, -0.5, 4.5 );
		CHECK( testBinner.coordToIndex(0)==0 );
		CHECK( testBinner.coordToIndex(1)==1 );
		CHECK( testBinner.coordToIndex(2)==2 );
		CHECK( testBinner.coordToIndex(3)==3 );
		CHECK( testBinner.coordToIndex(4)==4 );
		CHECK( testBinner.coordToIndex(-1)==(::BinnerTester<double,true,double>::InvalidBinIndex) ); // Underflow bin
		CHECK( testBinner.coordToIndex(-20.5)==(::BinnerTester<double,true,double>::InvalidBinIndex) );
		CHECK( testBinner.coordToIndex(-99999)==(::BinnerTester<double,true,double>::InvalidBinIndex) );
		CHECK( testBinner.coordToIndex(6)==(::BinnerTester<double,true,double>::InvalidBinIndex) ); // Overflow bin
		CHECK( testBinner.coordToIndex(7)==(::BinnerTester<double,true,double>::InvalidBinIndex) );
		CHECK( testBinner.coordToIndex(70)==(::BinnerTester<double,true,double>::InvalidBinIndex) );
		CHECK( testBinner.coordToIndex(99999)==(::BinnerTester<double,true,double>::InvalidBinIndex) );
		CHECK( testBinner.coordToIndex(std::numeric_limits<double>::quiet_NaN()) == (::BinnerTester<double,true,double>::InvalidBinIndex) );
		CHECK( testBinner.coordToIndex(-std::numeric_limits<double>::quiet_NaN()) == (::BinnerTester<double,true,double>::InvalidBinIndex) );
		CHECK( testBinner.getBins_().size()==5 );
	}
	WHEN( "Testing a 3D binner" )
	{
		const double inf=std::numeric_limits<double>::quiet_NaN();
		const size_t invalidIndex=::BinnerTester<double,true,double>::InvalidBinIndex;
		::BinnerTester<double,true,double,double,double> testBinner( 2, -0.5, 1.5, 2, 6.5, 8.5, 1, -4.5, -3.5 );
		CHECK( testBinner.coordToIndex(  0,  7, -4)==0 );
		CHECK( testBinner.coordToIndex(  0,  7,-99)==1 ); // z underflow
		CHECK( testBinner.coordToIndex(  0,  7,+99)==2 ); // z overflow
		CHECK( testBinner.coordToIndex(  0,  8, -4)==3 );
		CHECK( testBinner.coordToIndex(  0,  8,-99)==4 ); // z underflow
		CHECK( testBinner.coordToIndex(  0,  8,+99)==5 ); // z overflow
		CHECK( testBinner.coordToIndex(  0,-99, -4)==6 );
		CHECK( testBinner.coordToIndex(  0,-99,-99)==7 );
		CHECK( testBinner.coordToIndex(  0,-99,+99)==8 );
		CHECK( testBinner.coordToIndex(  0,+99, -4)==9 );
		CHECK( testBinner.coordToIndex(  0,+99,-99)==10 );
		CHECK( testBinner.coordToIndex(  0,+99,+99)==11 );
		CHECK( testBinner.coordToIndex(  1,  7, -4)==12 );
		CHECK( testBinner.coordToIndex(  1,  7,-99)==13 ); // z underflow
		CHECK( testBinner.coordToIndex(  1,  7,+99)==14 ); // z overflow
		CHECK( testBinner.coordToIndex(  1,  8, -4)==15 );
		CHECK( testBinner.coordToIndex(  1,  8,-99)==16 ); // z underflow
		CHECK( testBinner.coordToIndex(  1,  8,+99)==17 ); // z overflow
		CHECK( testBinner.coordToIndex(  1,-99, -4)==18 );
		CHECK( testBinner.coordToIndex(  1,-99,-99)==19 );
		CHECK( testBinner.coordToIndex(  1,-99,+99)==20 );
		CHECK( testBinner.coordToIndex(  1,+99, -4)==21 );
		CHECK( testBinner.coordToIndex(  1,+99,-99)==22 );
		CHECK( testBinner.coordToIndex(  1,+99,+99)==23 );
		CHECK( testBinner.coordToIndex(-99,  7, -4)==24 );
		CHECK( testBinner.coordToIndex(-99,  7,-99)==25 );
		CHECK( testBinner.coordToIndex(-99,  7,+99)==26 );
		CHECK( testBinner.coordToIndex(-99,  8, -4)==27 );
		CHECK( testBinner.coordToIndex(-99,  8,-99)==28 );
		CHECK( testBinner.coordToIndex(-99,  8,+99)==29 );
		CHECK( testBinner.coordToIndex(-99,-99, -4)==30 );
		CHECK( testBinner.coordToIndex(-99,-99,-99)==31 );
		CHECK( testBinner.coordToIndex(-99,-99,+99)==32 );
		CHECK( testBinner.coordToIndex(-99,+99, -4)==33 );
		CHECK( testBinner.coordToIndex(-99,+99,-99)==34 );
		CHECK( testBinner.coordToIndex(-99,+99,+99)==35 );
		CHECK( testBinner.coordToIndex(+99,  7, -4)==36 );
		CHECK( testBinner.coordToIndex(+99,  7,-99)==37 );
		CHECK( testBinner.coordToIndex(+99,  7,+99)==38 );
		CHECK( testBinner.coordToIndex(+99,  8, -4)==39 );
		CHECK( testBinner.coordToIndex(+99,  8,-99)==40 );
		CHECK( testBinner.coordToIndex(+99,  8,+99)==41 );
		CHECK( testBinner.coordToIndex(+99,-99, -4)==42 );
		CHECK( testBinner.coordToIndex(+99,-99,-99)==43 );
		CHECK( testBinner.coordToIndex(+99,-99,+99)==44 );
		CHECK( testBinner.coordToIndex(+99,+99, -4)==45 );
		CHECK( testBinner.coordToIndex(+99,+99,-99)==46 );
		CHECK( testBinner.coordToIndex(+99,+99,+99)==47 );
		CHECK( testBinner.coordToIndex(inf,  7, -4)==invalidIndex );
		CHECK( testBinner.coordToIndex(  0,inf, -4)==invalidIndex );
		CHECK( testBinner.coordToIndex(  0,  7,inf)==invalidIndex );
		CHECK( testBinner.coordToIndex(inf,inf,inf)==invalidIndex );
		CHECK( testBinner.getBins_().size()==48 );
	}
	WHEN( "Testing a 3D binner with no out-of-bounds" )
	{
		const double inf=std::numeric_limits<double>::quiet_NaN();
		const size_t invalidIndex=::BinnerTester<double,true,double>::InvalidBinIndex;
		::BinnerTester<double,false,double,double,double> testBinner( 2, -0.5, 1.5, 2, 6.5, 8.5, 1, -4.5, -3.5 );
		CHECK( testBinner.coordToIndex(  0,  7, -4)==0 );
		CHECK( testBinner.coordToIndex(  0,  7,-99)==invalidIndex ); // z underflow
		CHECK( testBinner.coordToIndex(  0,  7,+99)==invalidIndex ); // z overflow
		CHECK( testBinner.coordToIndex(  0,  8, -4)==1 );
		CHECK( testBinner.coordToIndex(  0,  8,-99)==invalidIndex ); // z underflow
		CHECK( testBinner.coordToIndex(  0,  8,+99)==invalidIndex ); // z overflow
		CHECK( testBinner.coordToIndex(  0,-99, -4)==invalidIndex );
		CHECK( testBinner.coordToIndex(  0,-99,-99)==invalidIndex );
		CHECK( testBinner.coordToIndex(  0,-99,+99)==invalidIndex );
		CHECK( testBinner.coordToIndex(  0,+99, -4)==invalidIndex );
		CHECK( testBinner.coordToIndex(  0,+99,-99)==invalidIndex );
		CHECK( testBinner.coordToIndex(  0,+99,+99)==invalidIndex );
		CHECK( testBinner.coordToIndex(  1,  7, -4)==2 );
		CHECK( testBinner.coordToIndex(  1,  7,-99)==invalidIndex ); // z underflow
		CHECK( testBinner.coordToIndex(  1,  7,+99)==invalidIndex ); // z overflow
		CHECK( testBinner.coordToIndex(  1,  8, -4)==3 );
		CHECK( testBinner.coordToIndex(  1,  8,-99)==invalidIndex ); // z underflow
		CHECK( testBinner.coordToIndex(  1,  8,+99)==invalidIndex ); // z overflow
		CHECK( testBinner.coordToIndex(  1,-99, -4)==invalidIndex );
		CHECK( testBinner.coordToIndex(  1,-99,-99)==invalidIndex );
		CHECK( testBinner.coordToIndex(  1,-99,+99)==invalidIndex );
		CHECK( testBinner.coordToIndex(  1,+99, -4)==invalidIndex );
		CHECK( testBinner.coordToIndex(  1,+99,-99)==invalidIndex );
		CHECK( testBinner.coordToIndex(  1,+99,+99)==invalidIndex );
		CHECK( testBinner.coordToIndex(-99,  7, -4)==invalidIndex );
		CHECK( testBinner.coordToIndex(-99,  7,-99)==invalidIndex );
		CHECK( testBinner.coordToIndex(-99,  7,+99)==invalidIndex );
		CHECK( testBinner.coordToIndex(-99,  8, -4)==invalidIndex );
		CHECK( testBinner.coordToIndex(-99,  8,-99)==invalidIndex );
		CHECK( testBinner.coordToIndex(-99,  8,+99)==invalidIndex );
		CHECK( testBinner.coordToIndex(-99,-99, -4)==invalidIndex );
		CHECK( testBinner.coordToIndex(-99,-99,-99)==invalidIndex );
		CHECK( testBinner.coordToIndex(-99,-99,+99)==invalidIndex );
		CHECK( testBinner.coordToIndex(-99,+99, -4)==invalidIndex );
		CHECK( testBinner.coordToIndex(-99,+99,-99)==invalidIndex );
		CHECK( testBinner.coordToIndex(-99,+99,+99)==invalidIndex );
		CHECK( testBinner.coordToIndex(+99,  7, -4)==invalidIndex );
		CHECK( testBinner.coordToIndex(+99,  7,-99)==invalidIndex );
		CHECK( testBinner.coordToIndex(+99,  7,+99)==invalidIndex );
		CHECK( testBinner.coordToIndex(+99,  8, -4)==invalidIndex );
		CHECK( testBinner.coordToIndex(+99,  8,-99)==invalidIndex );
		CHECK( testBinner.coordToIndex(+99,  8,+99)==invalidIndex );
		CHECK( testBinner.coordToIndex(+99,-99, -4)==invalidIndex );
		CHECK( testBinner.coordToIndex(+99,-99,-99)==invalidIndex );
		CHECK( testBinner.coordToIndex(+99,-99,+99)==invalidIndex );
		CHECK( testBinner.coordToIndex(+99,+99, -4)==invalidIndex );
		CHECK( testBinner.coordToIndex(+99,+99,-99)==invalidIndex );
		CHECK( testBinner.coordToIndex(+99,+99,+99)==invalidIndex );
		CHECK( testBinner.coordToIndex(inf,  7, -4)==invalidIndex );
		CHECK( testBinner.coordToIndex(  0,inf, -4)==invalidIndex );
		CHECK( testBinner.coordToIndex(  0,  7,inf)==invalidIndex );
		CHECK( testBinner.coordToIndex(inf,inf,inf)==invalidIndex );
		CHECK( testBinner.getBins_().size()==4 );
	}
}

SCENARIO( "Test that the NDimensionalBinner::binNumberToIndex protected method works as expected", "[ImplBasic]" )
{
	WHEN( "Testing a 1D binner" )
	{
		::BinnerTester<double,true,double> testBinner( 5, -0.5, 4.5 );
		CHECK( testBinner.binNumberToIndex(0)==0 );
		CHECK( testBinner.binNumberToIndex(1)==1 );
		CHECK( testBinner.binNumberToIndex(2)==2 );
		CHECK( testBinner.binNumberToIndex(3)==3 );
		CHECK( testBinner.binNumberToIndex(4)==4 );
		CHECK( testBinner.binNumberToIndex(::BinnerTester<double,true,double>::UnderflowBin)==5 );
		CHECK( testBinner.binNumberToIndex(::BinnerTester<double,true,double>::OverflowBin)==6 );
		CHECK( testBinner.binNumberToIndex(5) == (::BinnerTester<double,true,double>::InvalidBinIndex) );
		CHECK( testBinner.binNumberToIndex(6) == (::BinnerTester<double,true,double>::InvalidBinIndex) );
		CHECK( testBinner.binNumberToIndex(-3) == (::BinnerTester<double,true,double>::InvalidBinIndex) );
	}
	WHEN( "Testing a 1D binner with no out-of-bounds" )
	{
		::BinnerTester<double,false,double> testBinner( 5, -0.5, 4.5 );
		CHECK( testBinner.binNumberToIndex(0)==0 );
		CHECK( testBinner.binNumberToIndex(1)==1 );
		CHECK( testBinner.binNumberToIndex(2)==2 );
		CHECK( testBinner.binNumberToIndex(3)==3 );
		CHECK( testBinner.binNumberToIndex(4)==4 );
		CHECK( testBinner.binNumberToIndex(::BinnerTester<double,true,double>::UnderflowBin)==(::BinnerTester<double,true,double>::InvalidBinIndex) );
		CHECK( testBinner.binNumberToIndex(::BinnerTester<double,true,double>::OverflowBin)==(::BinnerTester<double,true,double>::InvalidBinIndex) );
		CHECK( testBinner.binNumberToIndex(5) == (::BinnerTester<double,true,double>::InvalidBinIndex) );
		CHECK( testBinner.binNumberToIndex(6) == (::BinnerTester<double,true,double>::InvalidBinIndex) );
		CHECK( testBinner.binNumberToIndex(-3) == (::BinnerTester<double,true,double>::InvalidBinIndex) );
	}
	WHEN( "Testing a 2D binner" )
	{
		constexpr auto Underflow=::BinnerTester<double,true,double>::UnderflowBin;
		constexpr auto Overflow=::BinnerTester<double,true,double>::OverflowBin;
		constexpr auto InvalidBinIndex=::BinnerTester<double,true,double,double>::InvalidBinIndex;

		::BinnerTester<double,true,double,double> testBinner( 3, -0.5, 2.5, 2, 4.5, 6.5 );
		CHECK( testBinner.binNumberToIndex(        0,        0) == 0 );
		CHECK( testBinner.binNumberToIndex(        0,        1) == 1 );
		CHECK( testBinner.binNumberToIndex(        0,Underflow) == 2 );
		CHECK( testBinner.binNumberToIndex(        0, Overflow) == 3 );
		CHECK( testBinner.binNumberToIndex(        1,        0) == 4 );
		CHECK( testBinner.binNumberToIndex(        1,        1) == 5 );
		CHECK( testBinner.binNumberToIndex(        1,Underflow) == 6 );
		CHECK( testBinner.binNumberToIndex(        1, Overflow) == 7 );
		CHECK( testBinner.binNumberToIndex(        2,        0) == 8 );
		CHECK( testBinner.binNumberToIndex(        2,        1) == 9 );
		CHECK( testBinner.binNumberToIndex(        2,Underflow) == 10 );
		CHECK( testBinner.binNumberToIndex(        2, Overflow) == 11 );
		CHECK( testBinner.binNumberToIndex(Underflow,        0) == 12 );
		CHECK( testBinner.binNumberToIndex(Underflow,        1) == 13 );
		CHECK( testBinner.binNumberToIndex(Underflow,Underflow) == 14 );
		CHECK( testBinner.binNumberToIndex(Underflow, Overflow) == 15 );
		CHECK( testBinner.binNumberToIndex(Overflow,         0) == 16 );
		CHECK( testBinner.binNumberToIndex(Overflow,         1) == 17 );
		CHECK( testBinner.binNumberToIndex(Overflow, Underflow) == 18 );
		CHECK( testBinner.binNumberToIndex(Overflow,  Overflow) == 19 );
		CHECK( testBinner.binNumberToIndex(        3,        0) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(        2,        2) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(        3,        2) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(        99,      99) == InvalidBinIndex );
	}
	WHEN( "Testing a 2D binner with no out-of-bounds" )
	{
		constexpr auto Underflow=::BinnerTester<double,false,double>::UnderflowBin;
		constexpr auto Overflow=::BinnerTester<double,false,double>::OverflowBin;
		constexpr auto InvalidBinIndex=::BinnerTester<double,false,double,double>::InvalidBinIndex;

		::BinnerTester<double,false,double,double> testBinner( 3, -0.5, 2.5, 2, 4.5, 6.5 );
		CHECK( testBinner.binNumberToIndex(        0,        0) == 0 );
		CHECK( testBinner.binNumberToIndex(        0,        1) == 1 );
		CHECK( testBinner.binNumberToIndex(        0,Underflow) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(        0, Overflow) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(        1,        0) == 2 );
		CHECK( testBinner.binNumberToIndex(        1,        1) == 3 );
		CHECK( testBinner.binNumberToIndex(        1,Underflow) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(        1, Overflow) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(        2,        0) == 4 );
		CHECK( testBinner.binNumberToIndex(        2,        1) == 5 );
		CHECK( testBinner.binNumberToIndex(        2,Underflow) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(        2, Overflow) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(Underflow,        0) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(Underflow,        1) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(Underflow,Underflow) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(Underflow, Overflow) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(Overflow ,        0) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(Overflow ,        1) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(Overflow ,Underflow) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(Overflow , Overflow) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(        3,        0) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(        2,        2) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(        3,        2) == InvalidBinIndex );
		CHECK( testBinner.binNumberToIndex(        99,      99) == InvalidBinIndex );
	}
}

SCENARIO( "Test that the NDimensionalBinner::get method works as expected", "[ImplBasic]" )
{
	WHEN( "Testing a 1D binner" )
	{
		::BinnerTester<double,true,double> testBinner( 5, -0.5, 4.5 );
		testBinner.setBins( {10,11,12,13,14,15,16} );
		testBinner.setInvalid( 17 );
		CHECK( testBinner.get(0)==10 );
		CHECK( testBinner.get(1)==11 );
		CHECK( testBinner.get(2)==12 );
		CHECK( testBinner.get(3)==13 );
		CHECK( testBinner.get(4)==14 );
		CHECK( testBinner.get(-1)==15 ); // Underflow bin
		CHECK( testBinner.get(-20.5)==15 );
		CHECK( testBinner.get(-99999)==15 );
		CHECK( testBinner.get(6)==16 ); // Overflow bin
		CHECK( testBinner.get(7)==16 );
		CHECK( testBinner.get(70)==16 );
		CHECK( testBinner.get(99999)==16 );
		CHECK( testBinner.get(std::numeric_limits<double>::quiet_NaN()) == 17 );
		CHECK( testBinner.get(-std::numeric_limits<double>::quiet_NaN()) == 17 );
	}
	WHEN( "Testing a 1D binner with no out-of-bounds" )
	{
		// Exactly the same test as before, except out of bounds values should give InvalidBinIndex
		::BinnerTester<double,false,double> testBinner( 5, -0.5, 4.5 );
		testBinner.setBins( {10,11,12,13,14} );
		testBinner.setInvalid( 17 );
		CHECK( testBinner.get(0)==10 );
		CHECK( testBinner.get(1)==11 );
		CHECK( testBinner.get(2)==12 );
		CHECK( testBinner.get(3)==13 );
		CHECK( testBinner.get(4)==14 );
		CHECK( testBinner.get(-1)==17 ); // Underflow bin
		CHECK( testBinner.get(-20.5)==17 );
		CHECK( testBinner.get(-99999)==17 );
		CHECK( testBinner.get(6)==17 ); // Overflow bin
		CHECK( testBinner.get(7)==17 );
		CHECK( testBinner.get(70)==17 );
		CHECK( testBinner.get(99999)==17 );
		CHECK( testBinner.get(std::numeric_limits<double>::quiet_NaN()) == 17 );
		CHECK( testBinner.get(-std::numeric_limits<double>::quiet_NaN()) == 17 );
		CHECK( testBinner.getBins_().size()==5 );
	}
	WHEN( "Testing a 3D binner" )
	{
		const double inf=std::numeric_limits<double>::quiet_NaN();
		const size_t invalidIndex=::BinnerTester<double,true,double>::InvalidBinIndex;
		::BinnerTester<double,true,double,double,double> testBinner( 3, -0.5, 2.5, 2, 6.5, 8.5, 2, -4.5, -2.5 );
		std::vector<double> fakeData;
		for( unsigned index=0; index<80; ++index ) fakeData.push_back( index+100 );
		testBinner.setBins( std::move(fakeData) );
		testBinner.setInvalid( 1000 );
		// See if the get() method works properly

		double expectedValue=100;

		for( const auto& xValue : { 0, 1, 2, -99, 99 } )
		{
			for( const auto& yValue : { 7, 8, -99, 99 } )
			{
				for( const auto& zValue : { -4, -3, -99, 99 } )
				{
					CHECK( testBinner.get( xValue, yValue, zValue ) == expectedValue );
					expectedValue+=1;
				}
			}
		}
	}
	WHEN( "Testing a 3D binner with no out-of-bounds" )
	{
		const double inf=std::numeric_limits<double>::quiet_NaN();
		const size_t invalidIndex=::BinnerTester<double,false,double,double,double>::InvalidBinIndex;
		::BinnerTester<double,false,double,double,double> testBinner( 3, -0.5, 2.5, 2, 6.5, 8.5, 2, -4.5, -2.5 );
		std::vector<double> fakeData;
		for( unsigned index=0; index<12; ++index ) fakeData.push_back( index+100 );
		testBinner.setBins( std::move(fakeData) );
		testBinner.setInvalid( 1000 );
		// See if the get() method works properly

		double expectedValue=100;

		for( const auto& xValue : { 0, 1, 2, -99, 99 } )
		{
			for( const auto& yValue : { 7, 8, -99, 99 } )
			{
				for( const auto& zValue : { -4, -3, -99, 99 } )
				{
					if( xValue<-0.5 || xValue>2.5 || yValue<6.5 || yValue>8.5 || zValue<-4.5 || zValue>-2.5 )
					{
						CHECK( testBinner.get( xValue, yValue, zValue ) == 1000 );
					}
					else
					{
						CHECK( testBinner.get( xValue, yValue, zValue ) == expectedValue );
						expectedValue+=1;
					}
				}
			}
		}
	}
}

SCENARIO( "Test that the methods using BinIndex work as expected", "[ImplBasic]" )
{
	WHEN( "Testing a 3D binner" )
	{
		const double inf=std::numeric_limits<double>::quiet_NaN();
		const size_t invalidIndex=::BinnerTester<double,true,double>::InvalidBinIndex;
		::BinnerTester<double,true,double,double,double> testBinner( 3, -0.5, 2.5, 2, 6.5, 8.5, 2, -4.5, -2.5 );
		std::vector<double> fakeData;
		for( unsigned index=0; index<80; ++index ) fakeData.push_back( index+100 );
		testBinner.setBins( std::move(fakeData) );
		testBinner.setInvalid( 1000 );
		// See if the get() method works properly

		double expectedValue=100;

		for( const auto& xValue : { 0, 1, 2, -99, 99 } )
		{
			for( const auto& yValue : { 7, 8, -99, 99 } )
			{
				for( const auto& zValue : { -4, -3, -99, 99 } )
				{
					auto binIndex=testBinner.binIndex( xValue, yValue, zValue );
					CHECK( testBinner.getFromBinIndex( binIndex ) == expectedValue );
					expectedValue+=1;
				}
			}
		}
	}
	WHEN( "Testing a 3D binner with no out-of-bounds" )
	{
		const double inf=std::numeric_limits<double>::quiet_NaN();
		const size_t invalidIndex=::BinnerTester<double,false,double,double,double>::InvalidBinIndex;
		::BinnerTester<double,false,double,double,double> testBinner( 3, -0.5, 2.5, 2, 6.5, 8.5, 2, -4.5, -2.5 );
		std::vector<double> fakeData;
		for( unsigned index=0; index<12; ++index ) fakeData.push_back( index+100 );
		testBinner.setBins( std::move(fakeData) );
		testBinner.setInvalid( 1000 );
		// See if the get() method works properly

		double expectedValue=100;

		for( const auto& xValue : { 0, 1, 2, -99, 99 } )
		{
			for( const auto& yValue : { 7, 8, -99, 99 } )
			{
				for( const auto& zValue : { -4, -3, -99, 99 } )
				{
					if( xValue<-0.5 || xValue>2.5 || yValue<6.5 || yValue>8.5 || zValue<-4.5 || zValue>-2.5 )
					{
						CHECK( testBinner.get( xValue, yValue, zValue ) == 1000 );
					}
					else
					{
						CHECK( testBinner.get( xValue, yValue, zValue ) == expectedValue );
						expectedValue+=1;
					}
				}
			}
		}
	}
}

SCENARIO( "Test that getting the axis works as expected", "[ImplBasic]" )
{
	WHEN( "Testing a 1D binner" )
	{
		implbasic::impl::NDimensionalBinner<double,true,double> testBinner( 5, -0.5, 4.5 );
		CHECK( testBinner.axis<0>().bins()==5 );
		CHECK( testBinner.axis<0>().lowerEdge()==-0.5 );
		CHECK( testBinner.axis<0>().upperEdge()==4.5 );
		CHECK( testBinner.axis<0>().binLowerEdge(0)==-0.5 );
		CHECK( testBinner.axis<0>().binUpperEdge(0)==0.5 );
		CHECK( testBinner.axis<0>().binLowerEdge(1)==0.5 );
		CHECK( testBinner.axis<0>().binUpperEdge(1)==1.5 );
		CHECK( testBinner.axis<0>().binLowerEdge(2)==1.5 );
		CHECK( testBinner.axis<0>().binUpperEdge(2)==2.5 );
		CHECK( testBinner.axis<0>().binLowerEdge(3)==2.5 );
		CHECK( testBinner.axis<0>().binUpperEdge(3)==3.5 );
		CHECK( testBinner.axis<0>().binLowerEdge(4)==3.5 );
		CHECK( testBinner.axis<0>().binUpperEdge(4)==4.5 );
	}
	WHEN( "Testing a 3D binner" )
	{
		implbasic::impl::NDimensionalBinner<double,true,double,double,double> testBinner( 5, -0.5, 4.5, 6, 15.5, 21.5, 7, 30.5, 37.5 );
		CHECK( testBinner.axis<0>().bins()==5 );
		CHECK( testBinner.axis<0>().lowerEdge()==-0.5 );
		CHECK( testBinner.axis<0>().upperEdge()==4.5 );
		CHECK( testBinner.axis<1>().bins()==6 );
		CHECK( testBinner.axis<1>().lowerEdge()==15.5 );
		CHECK( testBinner.axis<1>().upperEdge()==21.5 );
		CHECK( testBinner.axis<2>().bins()==7 );
		CHECK( testBinner.axis<2>().lowerEdge()==30.5 );
		CHECK( testBinner.axis<2>().upperEdge()==37.5 );
	}
}

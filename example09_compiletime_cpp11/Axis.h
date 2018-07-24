/*
 * This file is from some code I wrote a while ago for a much larger project. Hence the namespaces
 * don't make much sense for the ACCU talk.
 *
 * Copyright 2018 Mark Grimes (mark.grimes@rymapt.com)
 * I haven't decided on a licence, if anybody particularly wants to use it I'll consider open
 * sourcing it.
 */
#ifndef implbasic_impl_Axis_h
#define implbasic_impl_Axis_h

#include <vector>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <algorithm>

namespace implbasic
{
	namespace impl
	{
		/** @brief A class to convert between points in the data dimension to bin numbers
		 * @author Mark Grimes
		 * @date 15/Mar/2016
		 */
		template<typename T_value,typename T_binIndex=size_t>
		class Axis
		{
		public:
			typedef T_binIndex index_type;
			static constexpr T_binIndex UnderflowBin=std::numeric_limits<T_binIndex>::max()-1; ///< The index of the underflow bin
			static constexpr T_binIndex OverflowBin=std::numeric_limits<T_binIndex>::max(); ///< The index of the overflow bin
			static const T_value InvalidValue;

			Axis();
			Axis( unsigned int numberOfBins, const T_value& lowerEdge, const T_value& upperEdge ); ///< Constructor for fixed binning
			Axis( const std::vector<T_value>& binEdges ); ///< Constructor for variable width binning
			Axis( std::vector<T_value>&& binEdges ); ///< Constructor for variable width binning
			template<typename T_iterator>
			Axis( T_iterator begin, const T_iterator end ); ///< Constructor for variable width binning
			Axis( const Axis& other ) = default;
			Axis( Axis&& other ) = default;
			Axis& operator=( const Axis& other ) = default;
			Axis& operator=( Axis&& other ) = default;

			T_value lowerEdge() const;
			T_value upperEdge() const;
			T_binIndex bins() const;
			T_value binLowerEdge( T_binIndex index ) const;
			T_value binUpperEdge( T_binIndex index ) const;
			T_value binWidth( T_binIndex index ) const;
			T_value binCenter( T_binIndex index ) const;
			T_binIndex coordToIndex( const T_value& coord ) const;
		protected:
			// Note that the under and overflow bins are always at binEdges_[0] and binEdges_[1] respectively.
			std::vector<T_value> binEdges_;
		}; // end of class Axis
	} // end of namespace impl
} // end of namespace implbasic

template<typename T_value,typename T_binIndex>
constexpr T_binIndex implbasic::impl::Axis<T_value,T_binIndex>::UnderflowBin;

template<typename T_value,typename T_binIndex>
constexpr T_binIndex implbasic::impl::Axis<T_value,T_binIndex>::OverflowBin;

template<typename T_value,typename T_binIndex>
const T_value implbasic::impl::Axis<T_value,T_binIndex>::InvalidValue=std::numeric_limits<T_value>::infinity();

template<typename T_value,typename T_binIndex>
implbasic::impl::Axis<T_value,T_binIndex>::Axis()
{
	// Not sure whether to leave blank or fill with default data
	binEdges_.push_back( 0 );
	binEdges_.push_back( 1 );
}

template<typename T_value,typename T_binIndex>
implbasic::impl::Axis<T_value,T_binIndex>::Axis( unsigned int numberOfBins, const T_value& lowerEdge, const T_value& upperEdge )
{
	if( numberOfBins==0 ) throw std::runtime_error( "implbasic::impl::Axis<T_value,T_binIndex> was constructed with zero bins" );
	if( !( std::isfinite(lowerEdge) && std::isfinite(upperEdge) ) ) throw std::runtime_error( "implbasic::impl::Axis<T_value,T_binIndex> was constructed with non-finite edges" );

	// Use pointers because I can't swap const references
	const T_value* pLower=&lowerEdge;
	const T_value* pUpper=&upperEdge;
	if( *pUpper < *pLower ) std::swap( pLower, pUpper );

	binEdges_.reserve( numberOfBins+1 );
	for( unsigned int index=0; index<numberOfBins; ++index )
	{
		binEdges_.push_back( ((*pLower)*(numberOfBins-index)+(*pUpper)*index)/static_cast<T_value>(numberOfBins) );
	}
	binEdges_.push_back( *pUpper );
}

template<typename T_value,typename T_binIndex>
implbasic::impl::Axis<T_value,T_binIndex>::Axis( const std::vector<T_value>& binEdges )
	: binEdges_( binEdges )
{
	if( binEdges_.size()<2 ) throw std::runtime_error( "implbasic::impl::Axis<T_value,T_binIndex> was constructed with zero bins" );
	// Sort the binEdges vector in case it's not already in order
	std::sort( binEdges_.begin(), binEdges_.end() );

	if( !( std::isfinite(binEdges_.front()) && std::isfinite(binEdges_.back()) ) ) throw std::runtime_error( "implbasic::impl::Axis<T_value,T_binIndex> was constructed with non-finite edges" );
}

template<typename T_value,typename T_binIndex>
implbasic::impl::Axis<T_value,T_binIndex>::Axis( std::vector<T_value>&& binEdges )
	: binEdges_( std::forward<std::vector<T_value> >(binEdges) )
{
	if( binEdges_.size()<2 ) throw std::runtime_error( "implbasic::impl::Axis<T_value,T_binIndex> was constructed with zero bins" );
	// Sort the binEdges vector in case it's not already in order
	std::sort( binEdges_.begin(), binEdges_.end() );

	if( !( std::isfinite(binEdges_.front()) && std::isfinite(binEdges_.back()) ) ) throw std::runtime_error( "implbasic::impl::Axis<T_value,T_binIndex> was constructed with non-finite edges" );
}

template<typename T_value,typename T_binIndex> template<typename T_iterator>
implbasic::impl::Axis<T_value,T_binIndex>::Axis( T_iterator begin, const T_iterator end )
	: binEdges_(begin,end)
{
	if( binEdges_.size()<2 ) throw std::runtime_error( "implbasic::impl::Axis<T_value,T_binIndex> was constructed with zero bins" );
	// Sort the binEdges vector in case it's not already in order
	std::sort( binEdges_.begin(), binEdges_.end() );

	if( !( std::isfinite(binEdges_.front()) && std::isfinite(binEdges_.back()) ) ) throw std::runtime_error( "implbasic::impl::Axis<T_value,T_binIndex> was constructed with non-finite edges" );
}

template<typename T_value,typename T_binIndex>
T_value implbasic::impl::Axis<T_value,T_binIndex>::lowerEdge() const
{
	return binEdges_.front();
}

template<typename T_value,typename T_binIndex>
T_value implbasic::impl::Axis<T_value,T_binIndex>::upperEdge() const
{
	return binEdges_.back();
}

template<typename T_value,typename T_binIndex>
T_binIndex implbasic::impl::Axis<T_value,T_binIndex>::bins() const
{
	return binEdges_.size()-1;
}

template<typename T_value,typename T_binIndex>
T_value implbasic::impl::Axis<T_value,T_binIndex>::binLowerEdge( T_binIndex index ) const
{
	if( index==UnderflowBin ) return -std::numeric_limits<T_value>::infinity();
	else if( index==OverflowBin ) return binEdges_.back();
	else if( index<0 || index>=bins() ) throw std::runtime_error( "implbasic::impl::Axis<T_value,T_binIndex>::binLowerEdge was called with an invalid value" );
	else return binEdges_[index];
}

template<typename T_value,typename T_binIndex>
T_value implbasic::impl::Axis<T_value,T_binIndex>::binUpperEdge( T_binIndex index ) const
{
	if( index==UnderflowBin ) return binEdges_.front();
	else if( index==OverflowBin ) return std::numeric_limits<T_value>::infinity();
	else if( index<0 || index>=bins() ) throw std::runtime_error( "implbasic::impl::Axis<T_value,T_binIndex>::binUpperEdge was called with an invalid value" );
	else return binEdges_[index+1];
}

template<typename T_value,typename T_binIndex>
T_value implbasic::impl::Axis<T_value,T_binIndex>::binWidth( T_binIndex index ) const
{
	if( index==UnderflowBin ) return -std::numeric_limits<T_value>::infinity();
	else if( index==OverflowBin ) return std::numeric_limits<T_value>::infinity();
	else if( index<0 || index>=bins() ) throw std::runtime_error( "implbasic::impl::Axis<T_value,T_binIndex>::binWidth was called with an invalid value" );
	else return binEdges_[index+1]-binEdges_[index];
}

template<typename T_value,typename T_binIndex>
T_value implbasic::impl::Axis<T_value,T_binIndex>::binCenter( T_binIndex index ) const
{
	if( index==UnderflowBin ) return -std::numeric_limits<T_value>::infinity();
	else if( index==OverflowBin ) return std::numeric_limits<T_value>::infinity();
	else if( index<0 || index>=bins() ) throw std::runtime_error( "implbasic::impl::Axis<T_value,T_binIndex>::binCenter was called with an invalid value" );
	else return binLowerEdge(index)+binWidth(index)/static_cast<T_value>(2);
}

template<typename T_value,typename T_binIndex>
T_binIndex implbasic::impl::Axis<T_value,T_binIndex>::coordToIndex( const T_value& coord ) const
{
	if( coord<lowerEdge() ) return UnderflowBin;
	else if( coord>=upperEdge() ) return OverflowBin;

	auto iFindResult=std::upper_bound( binEdges_.begin(), binEdges_.end(), coord );
	--iFindResult;
	return (iFindResult-binEdges_.begin());
}

#endif

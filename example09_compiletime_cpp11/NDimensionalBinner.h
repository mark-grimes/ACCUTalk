/*
 * This file is from some code I wrote a while ago for a much larger project. Hence the namespaces
 * don't make much sense for the ACCU talk.
 *
 * Copyright 2018 Mark Grimes (mark.grimes@rymapt.com)
 * I haven't decided on a licence, if anybody particularly wants to use it I'll consider open
 * sourcing it.
 */
#ifndef implbasic_impl_NDimensionalBinner_h
#define implbasic_impl_NDimensionalBinner_h

#include <vector>
#include "Axis.h"

namespace implbasic
{
	namespace impl
	{
		// Need to forward declare the class before including NDimensionalBinner_detail.h
		template<typename T_bin,bool IncludeOverflow,typename... T_variadic> // This is the base level
		class NDimensionalBinner;
	}
}
#include "NDimensionalBinner_detail.h"


namespace implbasic
{
	namespace impl
	{
		/** @brief Class that can put things into bins.
		 *
		 * The dimensionality is set by the number of types given in the template list. The first type
		 * supplied is the type of the histogram bin, followed by the type for each axis. Hence you need
		 * numDimensions+1 types.
		 *
		 * The template argument IncludeOverflow should usually be true. This allocates an under and over
		 * flow bin for entries that don't fit into the bin settings given. For very high dimensionality
		 * it adds a large number of bins so setting to false will save space.
		 *
		 * @author Mark Grimes
		 * @date 07/Aug/2016
		 */
		template<typename T_bin,bool IncludeOverflow,typename... T_variadic> // This is the base level
		class NDimensionalBinner
		{
		protected:
			struct UseProtectedConstructor { size_t totalBins; }; // Just some dummy type to resolve ambiguity in templated constructors
			NDimensionalBinner( UseProtectedConstructor token ) : bins_(token.totalBins) {}
			static constexpr int overflowOffset() { return IncludeOverflow ? 2 : 0; }
			unsigned nextStride() const { return 1; }
			static constexpr size_t dimensions() { return 0; }
			size_t coordToIndex() const { return 0; }
			size_t binNumberToIndex() const { return 0; }
			static constexpr size_t InvalidBinIndex=std::numeric_limits<size_t>::max(); ///< The bin index returned when something has gone wrong

			std::vector<T_bin> bins_;
			/// The entry when NaN values are given. Also includes out of bounds if IncludeOverflow is false (otherwise each under/overflow has its own bin).
			T_bin invalidEntry_;
		};

		template<typename T_bin,bool IncludeOverflow,typename T_axis,typename... T_otheraxes>
		class NDimensionalBinner<T_bin,IncludeOverflow,T_axis,T_otheraxes...> : protected NDimensionalBinner<T_bin,IncludeOverflow,T_otheraxes...>
		{
		protected:
			typedef NDimensionalBinner<T_bin,IncludeOverflow,T_otheraxes...> BaseClass;
		public:
			typedef T_bin value_type;
			template<size_t Dimension> using axis_type = typename detail::AxisType<Dimension,T_axis,T_otheraxes...>::type;
			typedef size_t axis_index_type;
			static constexpr axis_index_type UnderflowBin=Axis<T_axis,axis_index_type>::UnderflowBin; ///< The index of the underflow bin
			static constexpr axis_index_type OverflowBin=Axis<T_axis,axis_index_type>::OverflowBin; ///< The index of the overflow bin

			template<typename... T_otherargs>
			NDimensionalBinner( unsigned int numberOfBins, const T_axis& lowerEdge, const T_axis& upperEdge, T_otherargs... otherArgs )
				: BaseClass(UseProtectedConstructor{numberOfBins+this->overflowOffset()},otherArgs...), axis_(numberOfBins,lowerEdge,upperEdge), stride_( BaseClass::nextStride() )
			{
				// No operation besides the initialiser list
			}
			template<typename... T_otherargs>
			NDimensionalBinner( const std::vector<T_axis>& binEdges, T_otherargs... otherArgs )
				: BaseClass(UseProtectedConstructor{binEdges.size()-1+this->overflowOffset()},otherArgs...), axis_(binEdges), stride_( BaseClass::nextStride() )
			{
				// No operation besides the initialiser list
			}
			template<typename... T_otherargs>
			NDimensionalBinner( std::vector<T_axis>&& binEdges, T_otherargs... otherArgs )
				: BaseClass(UseProtectedConstructor{binEdges.size()-1+this->overflowOffset()},otherArgs...), axis_(std::forward<std::vector<T_axis> >(binEdges)), stride_( BaseClass::nextStride() )
			{
				// No operation besides the initialiser list
			}

			static constexpr size_t dimensions()
			{
				return BaseClass::dimensions()+1;
			}

			T_bin& get( const T_axis& arg1, T_otheraxes... otherArgs )
			{
				size_t index=coordToIndex( arg1, otherArgs... );
				if( index==InvalidBinIndex ) return this->invalidEntry_;
				else return this->bins_[index];
			}

			const T_bin& get( const T_axis& arg1, T_otheraxes... otherArgs ) const
			{
				size_t index=coordToIndex( arg1, otherArgs... );
				if( index==InvalidBinIndex ) return this->invalidEntry_;
				else return this->bins_[index];
			}

			T_bin& getInvalidEntry()
			{
				return this->invalidEntry_;
			}

			const T_bin& getInvalidEntry() const
			{
				return this->invalidEntry_;
			}

			template<typename... T_otherArgs>
			T_bin& getFromBinNumbers( typename Axis<T_axis>::index_type axisBinNumber, T_otherArgs... otherBinNumbers )
			{
				size_t index=binNumberToIndex( axisBinNumber, otherBinNumbers... );
				if( index==InvalidBinIndex ) return this->invalidEntry_;
				else return this->bins_[index];
			}

			template<typename... T_otherArgs>
			const T_bin& getFromBinNumbers( typename Axis<T_axis>::index_type axisBinNumber, T_otherArgs... otherBinNumbers ) const
			{
				size_t index=binNumberToIndex( axisBinNumber, otherBinNumbers... );
				if( index==InvalidBinIndex ) return this->invalidEntry_;
				else return this->bins_[index];
			}

			template<typename... T_otherArgs>
			T_bin& getFromBinIndex( const axis_index_type& index )
			{
				if( index>=this->bins_.size() ) return this->invalidEntry_;
				else return this->bins_[index];
			}

			template<typename... T_otherArgs>
			const T_bin& getFromBinIndex( const axis_index_type& index ) const
			{
				if( index>=this->bins_.size() ) return this->invalidEntry_;
				else return this->bins_[index];
			}

			axis_index_type binIndex( const T_axis& arg1, T_otheraxes... otherArgs ) const
			{
				return coordToIndex( arg1, otherArgs... );
			}

			template<typename... T_otherArgs>
			axis_index_type binIndexFromBinNumbers( typename Axis<T_axis>::index_type axisBinNumber, T_otherArgs... otherBinNumbers ) const
			{
				return binNumberToIndex( axisBinNumber, otherBinNumbers... );
			}

			axis_index_type totalBins() const
			{
				// +1 for the invalidEntry_ bin
				return this->bins_.size()+1;
			}

			template<size_t Dimension>
			const Axis<axis_type<Dimension>,axis_index_type>& axis() const
			{
				return GetDimension<Dimension>::axis_;
			}
		protected:
			template<size_t Dimension> using GetDimension = typename detail::BinnerType<Dimension,T_bin,IncludeOverflow,T_axis,T_otheraxes...>::type;
			typedef typename NDimensionalBinner<T_bin,IncludeOverflow>::UseProtectedConstructor UseProtectedConstructor;
			static constexpr size_t InvalidBinIndex=NDimensionalBinner<T_bin,IncludeOverflow>::InvalidBinIndex;

			template<typename... T_otherargs>
			NDimensionalBinner( UseProtectedConstructor token, unsigned int numberOfBins, const T_axis& lowerEdge, const T_axis& upperEdge, T_otherargs... otherArgs )
				: BaseClass(UseProtectedConstructor{token.totalBins*(numberOfBins+this->overflowOffset())},otherArgs...), axis_(numberOfBins,lowerEdge,upperEdge), stride_( BaseClass::nextStride() )
			{
				// No operation besides the initialiser list
			}
			template<typename... T_otherargs>
			NDimensionalBinner( UseProtectedConstructor token, const std::vector<T_axis>& binEdges, T_otherargs... otherArgs )
				: BaseClass(UseProtectedConstructor{token.totalBins*(binEdges.size()-1+this->overflowOffset())},otherArgs...), axis_(binEdges), stride_( BaseClass::nextStride() )
			{
				// No operation besides the initialiser list
			}
			template<typename... T_otherargs>
			NDimensionalBinner( UseProtectedConstructor token, std::vector<T_axis>&& binEdges, T_otherargs... otherArgs )
				: BaseClass(UseProtectedConstructor{token.totalBins*(binEdges.size()-1+this->overflowOffset())},otherArgs...), axis_(std::forward<std::vector<T_axis> >(binEdges)), stride_( BaseClass::nextStride() )
			{
				// No operation besides the initialiser list
			}

			unsigned nextStride() const
			{
				return BaseClass::nextStride()*(axis_.bins()+this->overflowOffset());
			}
			/** @brief Returns the array index into bins_ for the axis coordinates supplied. */
			size_t coordToIndex( const T_axis& arg1, T_otheraxes... otherArgs ) const
			{
				static_assert( sizeof...(otherArgs)==sizeof...(T_otheraxes), "The number of arguments supplied does not match the dimension of the histogram" );
				if( std::isnan(arg1) ) return InvalidBinIndex;

				typename Axis<T_axis>::index_type thisAxisCoord=axis_.coordToIndex(arg1);
				if( !IncludeOverflow && (thisAxisCoord==Axis<T_axis>::UnderflowBin || thisAxisCoord==Axis<T_axis>::OverflowBin) ) return InvalidBinIndex;

				// If it's under or overflow change to be size+1 or +2 respectively (i.e. put underflow at
				// the array index directly after normal entries, and overflow after that).
				if( thisAxisCoord==Axis<T_axis>::UnderflowBin ) thisAxisCoord=axis_.bins();
				else if( thisAxisCoord==Axis<T_axis>::OverflowBin ) thisAxisCoord=axis_.bins()+1;

				//  Multiply by the stride for this dimension, and add on the index contribution from lower dimensions
				const size_t nextDimension=BaseClass::coordToIndex( otherArgs... );
				if( nextDimension==InvalidBinIndex ) return InvalidBinIndex;
				else return stride_*thisAxisCoord+nextDimension;
			}

			/** @brief Returns the array index into bins_ for the axis bin numbers supplied. */
			template<typename... T_otherArgs>
			size_t binNumberToIndex( typename Axis<T_axis>::index_type axisBinNumber, T_otherArgs... otherBinNumbers ) const
			{
				if( axisBinNumber==Axis<T_axis>::UnderflowBin || axisBinNumber==Axis<T_axis>::OverflowBin )
				{
					if( !IncludeOverflow ) return InvalidBinIndex;

					// If it's under or overflow change to be size+1 or +2 respectively (i.e. put underflow at
					// the array index directly after normal entries, and overflow after that).
					if( axisBinNumber==Axis<T_axis>::UnderflowBin ) axisBinNumber=axis_.bins();
					else if( axisBinNumber==Axis<T_axis>::OverflowBin ) axisBinNumber=axis_.bins()+1;
				}
				else if( axisBinNumber<0 || axisBinNumber>=axis_.bins() ) return InvalidBinIndex;

				//  Multiply by the stride for this dimension, and add on the index contribution from lower dimensions
				const size_t nextDimension=BaseClass::binNumberToIndex( otherBinNumbers... );
				if( nextDimension==InvalidBinIndex ) return InvalidBinIndex;
				else return stride_*axisBinNumber+nextDimension;
			}

			Axis<T_axis,axis_index_type> axis_;
			const size_t stride_;
		};

	} // end of namespace impl
} // end of namespace implbasic

#endif

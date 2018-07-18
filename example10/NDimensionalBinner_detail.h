/*
 * This file is from some code I wrote a while ago for a much larger project. Hence the namespaces
 * don't make much sense for the ACCU talk.
 *
 * Copyright 2018 Mark Grimes (mark.grimes@rymapt.com)
 * I haven't decided on a licence, if anybody particularly wants to use it I'll consider open
 * sourcing it.
 */
#ifndef implbasic_impl_NDimensionalBinner_detail_h
#define implbasic_impl_NDimensionalBinner_detail_h

#include <cstddef> // Required for size_t

namespace implbasic
{
	namespace impl
	{
		namespace detail
		{
			/** @brief Helper class to get the type of the axis for a given level in the inheritance hierarchy.
			 *
			 * Basically just returns the "Dimension"th template parameter. E.g.
			 *
			 *     AxisType<0,double,char,int,float>::type gives double
			 *     AxisType<1,double,char,int,float>::type gives char
			 *     AxisType<2,double,char,int,float>::type gives int
			 *     AxisType<3,double,char,int,float>::type gives float
			 *     AxisType<4,double,char,int,float>::type won't compile
			 *
			 * @author Mark Grimes
			 * @date 21/Mar/2016 */
			template<size_t Dimension,typename T_axis,typename... T_otheraxes>
			struct AxisType
			{
				typedef typename AxisType<Dimension-1,T_otheraxes...>::type type;
			};

			template<typename T_axis,typename... T_otheraxes>
			struct AxisType<0,T_axis,T_otheraxes...>
			{
				typedef T_axis type;
			};

			/** @brief Helper class to get the type of a given class in the inheritance hierarchy.
			 *
			 * Gives the type of dimension "Dimension" of the NDimensionalHistogram with the other template
			 * parameters. E.g.
			 *
			 *     BinnerType<2,T_bin,IncludeOverflow,double,char,int,float>::type
			 *     BinnerType<3,T_bin,IncludeOverflow,double,char,int,float>::type
			 *
			 * would give
			 *
			 *     BinnerType<T_bin,IncludeOverflow,int,float>::type
			 *     BinnerType<T_bin,IncludeOverflow,float>::type
			 *
			 * respectively (i.e. the 2nd and 3rd binners in the inheritance chain).
			 *
			 * @author Mark Grimes
			 * @date 21/Mar/2016 */
			template<size_t Dimension,typename T_bin,bool IncludeOverflow,typename T_axis,typename... T_otheraxes>
			struct BinnerType
			{
				typedef typename BinnerType<Dimension-1,T_bin,IncludeOverflow,T_otheraxes...>::type type;
			};

			template<typename T_bin,bool IncludeOverflow,typename T_axis,typename... T_otheraxes>
			struct BinnerType<0,T_bin,IncludeOverflow,T_axis,T_otheraxes...>
			{
				typedef NDimensionalBinner<T_bin,IncludeOverflow,T_axis,T_otheraxes...> type;
			};
		} // end of "namespace detail"
	} // end of namespace impl
} // end of namespace implbasic

#endif

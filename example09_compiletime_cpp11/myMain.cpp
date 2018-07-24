#include "NDimensionalBinner.h"

struct HistogramBin
{
	float totalWeight=0;
	unsigned entries=0;
	float sumOfWeightsSquared=0; // sqrt of this will give the poisson error of bin height
};

unsigned long long myMain()
{
	implbasic::impl::NDimensionalBinner<HistogramBin,true,double,double> binner( 10, -0.5, 9.5, 5, -2, 2 );

	std::vector<std::pair<double,double>> exampleData{ {0,0}, {0,-0.1}, {0,0.1}, {0,3} };
	for( const auto& datapoint : exampleData )
	{
		HistogramBin& bin=binner.get(datapoint.first,datapoint.second);
		constexpr float weight=1; // Could weight entries, but don't bother in this example
		bin.totalWeight+=weight;
		bin.entries+=1;
		bin.sumOfWeightsSquared+=weight*weight;
	}

	return binner.get(0,0).totalWeight;
}

#ifndef GCN64_ANALYZER_H
#define GCN64_ANALYZER_H

#include <Analyzer.h>
#include "GCN64AnalyzerResults.h"
#include "GCN64SimulationDataGenerator.h"

class GCN64AnalyzerSettings;
class ANALYZER_EXPORT GCN64Analyzer : public Analyzer2
{
public:
	GCN64Analyzer();
	virtual ~GCN64Analyzer();

	virtual void SetupResults();
	virtual void WorkerThread();

	virtual U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channels );
	virtual U32 GetMinimumSampleRateHz();

	virtual const char* GetAnalyzerName() const;
	virtual bool NeedsRerun();

#pragma warning( push )
#pragma warning( disable : 4251 )
protected: //vars
	std::auto_ptr< GCN64AnalyzerSettings > mSettings;
	std::auto_ptr< GCN64AnalyzerResults > mResults;
	AnalyzerChannelData* mGCN64Data;

	GCN64SimulationDataGenerator mSimulationDataGenerator;
	bool mSimulationInitilized;

	U32 mSampleRateHz;
#pragma warning( pop )
};

extern "C" ANALYZER_EXPORT const char* __cdecl GetAnalyzerName();
extern "C" ANALYZER_EXPORT Analyzer* __cdecl CreateAnalyzer( );
extern "C" ANALYZER_EXPORT void __cdecl DestroyAnalyzer( Analyzer* analyzer );

#endif //GCN64_ANALYZER_H

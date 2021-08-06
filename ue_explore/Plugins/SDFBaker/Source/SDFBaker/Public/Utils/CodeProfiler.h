
// author : spr1ngd
// desc   : code profiler utility 时间应该不准确，但时间占比应该是正相关的，具有调试参考价值，主要是快

#pragma once
#include "CoreMinimal.h"
#include <time.h>
#include "UObject/NameTypes.h"

namespace S 
{
	class FCodeProfilerItem
	{
	public:
		float epsilon;
		FName profilerName;
		clock_t start;
		clock_t end;

		float EpsilonInSeconds() { return epsilon / 1000.0f; }
		float EpsilonInMillisecond() { return epsilon; }
	};

	class SDFBAKER_API FCodeProfiler 
	{
	private:
		static TMap<FName, FCodeProfilerItem*> profilers;
	public:
		static void BeginProfiler(FName profilerName);
		static float EndProfiler(FName profilerName,bool continuous = false, bool bPrintLog = false);
	};
}
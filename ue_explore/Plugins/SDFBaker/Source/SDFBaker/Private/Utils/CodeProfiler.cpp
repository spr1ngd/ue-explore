
#include "Utils/CodeProfiler.h"
#include "Engine/Engine.h"

using namespace S;

TMap<FName, S::FCodeProfilerItem*> S::FCodeProfiler::profilers;

void S::FCodeProfiler::BeginProfiler(FName profilerName)
{
	FCodeProfilerItem* profiler = nullptr;
	if (profilers.Contains(profilerName))
	{
		profiler = profilers[profilerName];
		profiler->start = clock();
		return;
	}
	profiler = new FCodeProfilerItem();
	profiler->profilerName = profilerName;
	profiler->start = clock();
	profilers.Add(profilerName, profiler);
}

float S::FCodeProfiler::EndProfiler(FName profilerName, bool continuous /*= false*/, bool bPrintLog /*= false*/)
{
	if (!profilers.Contains(profilerName))
		return -1.0f;
	FCodeProfilerItem* profiler = profilers[profilerName];
	profiler->end = clock();
	profiler->epsilon += profiler->end - profiler->start;
	float epsilon = profiler->EpsilonInMillisecond();
	if (bPrintLog) {
		GEngine->AddOnScreenDebugMessage(-1, 1000.0f, FColor::Red, FString::Printf(TEXT("%s : [%f]ms"), *profilerName.ToString(), epsilon));
		UE_LOG(LogTemp, Log, TEXT("%s : [%f]ms"), *profilerName.ToString(), epsilon);
	}
	if (!continuous) {
		profilers.Remove(profilerName);
		delete profiler;
	}
	return epsilon;
}
// Copyright Epic Games, Inc. All Rights Reserved.

#include "ue_explore.h"
#include "Modules/ModuleManager.h"
#include "Misc/Paths.h"

void Fue_exploreModule::StartupModule()
{
	FString shaderDirectory = FPaths::Combine(FPaths::ProjectDir(),TEXT("CGIncludes"));
	AddShaderSourceDirectoryMapping("/cginc",shaderDirectory);
}

void Fue_exploreModule::ShutdownModule()
{

}

IMPLEMENT_PRIMARY_GAME_MODULE(Fue_exploreModule, ue_explore, "ue_explore");

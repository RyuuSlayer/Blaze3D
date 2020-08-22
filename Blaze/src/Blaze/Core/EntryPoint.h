#pragma once
#include "Blaze/Core/Core.h"

#ifdef BZ_PLATFORM_WINDOWS

extern Blaze::Application* Blaze::CreateApplication();

int main(int argc, char** argv)
{
	Blaze::Log::Init();

	BZ_PROFILE_BEGIN_SESSION("Startup", "BlazeProfile-Startup.json");
	auto app = Blaze::CreateApplication();
	BZ_PROFILE_END_SESSION();

	BZ_PROFILE_BEGIN_SESSION("Runtime", "BlazeProfile-Runtime.json");
	app->Run();
	BZ_PROFILE_END_SESSION();

	BZ_PROFILE_BEGIN_SESSION("Startup", "BlazeProfile-Shutdown.json");
	delete app;
	BZ_PROFILE_END_SESSION();
}

#endif
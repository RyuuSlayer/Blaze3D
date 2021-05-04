#pragma once
#include "Blaze/Core/Base.h"
#include "Blaze/Core/Application.h"

#ifdef BZ_PLATFORM_WINDOWS

extern Blaze::Application* Blaze::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Blaze::Log::Init();

	BZ_PROFILE_BEGIN_SESSION("Startup", "BlazeProfile-Startup.json");
	auto app = Blaze::CreateApplication({ argc, argv });
	BZ_PROFILE_END_SESSION();

	BZ_PROFILE_BEGIN_SESSION("Runtime", "BlazeProfile-Runtime.json");
	app->Run();
	BZ_PROFILE_END_SESSION();

	BZ_PROFILE_BEGIN_SESSION("Shutdown", "BlazeProfile-Shutdown.json");
	delete app;
	BZ_PROFILE_END_SESSION();
}

#endif

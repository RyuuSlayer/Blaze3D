#pragma once

#ifdef BZ_PLATFORM_WINDOWS

extern Blaze::Application* Blaze::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Blaze::CreateApplication();
	app->Run();
	delete app;
}

#endif
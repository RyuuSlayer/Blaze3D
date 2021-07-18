#include <Blaze.h>
#include <Blaze/Core/EntryPoint.h>

#include "Sandbox2D.h"

#include "ExampleLayer.h"

class Sandbox : public Blaze::Application
{
public:
	Sandbox(Blaze::ApplicationCommandLineArgs args)
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

Blaze::Application* Blaze::CreateApplication(Blaze::ApplicationCommandLineArgs args)
{
	return new Sandbox(args);
}

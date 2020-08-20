#include <Blaze.h>

class ExampleLayer : public Blaze::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		BZ_INFO("ExampleLayer::Update");
	}

	void OnEvent(Blaze::Event& event) override
	{
		BZ_TRACE("{0}", event);
	}

};

class Sandbox : public Blaze::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Blaze::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

Blaze::Application* Blaze::CreateApplication()
{
	return new Sandbox();
}
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
		if (Blaze::Input::IsKeyPressed(BZ_KEY_TAB))
			BZ_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Blaze::Event& event) override
	{
		if (event.GetEventType() == Blaze::EventType::KeyPressed)
		{
			Blaze::KeyPressedEvent& e = (Blaze::KeyPressedEvent&)event;
			if (e.GetKeyCode() == BZ_KEY_TAB)
				BZ_TRACE("Tab key is pressed (event)!");
			BZ_TRACE("{0}", (char)e.GetKeyCode());
		}
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
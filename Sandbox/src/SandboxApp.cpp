#include <Blaze.h>

class Sandbox : public Blaze::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Blaze::Application* Blaze::CreateApplication()
{
	return new Sandbox();
}
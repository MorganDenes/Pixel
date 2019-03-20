#include <pixel.h>

class Sandbox : public Pxl::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};


Pxl::Application* Pxl::CreateApplication()
{
	return new Sandbox();
}
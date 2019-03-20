#pragma once

#ifdef PXL_PLATFORM_WINDOWS

extern Pxl::Application* Pxl::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Pxl::CreateApplication();
	app->Run();
	delete app;
}

#endif // PXL_PLATFORM_WINDOWS

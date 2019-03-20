#pragma once

#ifdef PXL_PLATFORM_WINDOWS

extern Pxl::Application* Pxl::CreateApplication();

int main(int argc, char** argv)
{
	Pxl::Log::Init();
	PXL_CORE_WARN("Initialized Log!");
	int a = 5;
	PXL_INFO("Hello! Var={0}", a);

	auto app = Pxl::CreateApplication();
	app->Run();
	delete app;
}

#endif // PXL_PLATFORM_WINDOWS

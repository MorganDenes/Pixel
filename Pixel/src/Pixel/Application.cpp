#include "pxlpch.h"
#include "Application.h"

#include "Pixel/Event/ApplicationEvent.h"
#include "Pixel/Log.h"


namespace Pxl {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		PXL_TRACE(e);

		while (true);
	}

}

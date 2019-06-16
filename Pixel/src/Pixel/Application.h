#pragma once
#include "Core.h"

#include "Pixel/Event/Event.h"


namespace Pxl {

	class PIXEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in Client
	Application* CreateApplication();
}

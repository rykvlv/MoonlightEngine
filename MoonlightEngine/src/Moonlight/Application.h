#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace ML {
	class MOONLIGHT_API Application {
	public:
		Application();
		virtual ~Application();

		void run();
	};

	//To be defined in a client
	Application* createApplication();
}



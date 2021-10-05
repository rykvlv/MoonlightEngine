#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace ML {
	class MOONLIGHT_API Application {
	public:
		Application();
		virtual ~Application();

		void run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running;
	};

	//To be defined in a client
	Application* createApplication();
}

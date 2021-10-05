#include "mlpch.h"
#include "Application.h"

#include "Moonlight/Events/ApplicationEvent.h"
#include "Moonlight/Log.h"

#include <GLFW/glfw3.h>

namespace ML {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}

	void Application::run() {
		m_Running = true;
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->onUpdate();
		}
	}
}
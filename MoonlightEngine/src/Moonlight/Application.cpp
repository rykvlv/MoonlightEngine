#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace ML {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::run() {
		WindowResizeEvent e(1280, 768);
		ML_TRACE(e);
		if (e.isInCategory(EventCategoryApplication)) {
			ML_TRACE(e);
		}
		if (e.isInCategory(EventCategoryInput)) {
			ML_TRACE(e);
		}
		while (true) {

		}
	}
}
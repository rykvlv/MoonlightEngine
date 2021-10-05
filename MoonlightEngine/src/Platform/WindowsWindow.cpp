#include "mlpch.h"
#include "WindowsWindow.h"

namespace ML {
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProperties& properties) {
		return new WindowsWindow(properties);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& properties) {
		init(properties);
	}

	WindowsWindow::~WindowsWindow() {
		shutdown();
	}

	void WindowsWindow::init(const WindowProperties& properties) {
		m_Data.title = properties.title;
		m_Data.width = properties.width;
		m_Data.height = properties.height;

		ML_CORE_INFO("Creating window {0} ({1}, {2})", properties.title, properties.width, properties.height);

		if (!s_GLFWInitialized) {
			int success = glfwInit();
			ML_CORE_ASSERT(success, "Failed to initialize GLFW!");
			
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)properties.width, 
			                        (int)properties.height, 
			                        properties.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		setVSync(true);
	}

	void WindowsWindow::shutdown() {
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::onUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::setVSync(bool enabled) {
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::isVSync() const {
		return m_Data.VSync;
	}
}

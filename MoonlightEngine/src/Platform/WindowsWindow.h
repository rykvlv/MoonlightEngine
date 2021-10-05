#pragma once

#include "Moonlight/Window.h"

#include <GLFW/glfw3.h>

namespace ML {
	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProperties& properites);
		virtual ~WindowsWindow();

		void onUpdate() override;

		inline unsigned int getWidth() const override { return m_Data.width; }
		inline unsigned int getHeight() const override { return m_Data.height; }

		inline void setEventCallback(const eventCallbackFn& callback) override { m_Data.eventCallback = callback; }
		void setVSync(bool enabled) override;
		bool isVSync() const override;
	private:
		virtual void init(const WindowProperties& properties);
		virtual void shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowData {
			std::string title;
			unsigned int width, height;
			bool VSync;

			eventCallbackFn eventCallback;
		};

		WindowData m_Data;
	};
}


#pragma once

#include "mlpch.h"

#include "Moonlight/Core.h"
#include "Moonlight/Events/Event.h"

namespace ML {
	struct WindowProperties {
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProperties(const std::string& title = "Moonlight Engine",
			             unsigned int width = 1280,
			             unsigned int height = 768)
			: title(title), width(width), height(height)
		{
		}
	};

	class MOONLIGHT_API Window {
	public:
		using eventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		virtual void setEventCallback(const eventCallbackFn& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		static Window* Create(const WindowProperties& props = WindowProperties());
	};
}
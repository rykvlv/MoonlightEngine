#pragma once

#ifdef ML_PLATFORM_WINDOWS

extern ML::Application* ML::createApplication();

int main(int argc, char** argv) {
	ML::Log::init();
	ML_CORE_WARN("Initiliazed Log");
	ML_INFO("Welcome to Moonlight Engine");
	auto app = ML::createApplication();
	app->run();
	delete app;
}

#endif
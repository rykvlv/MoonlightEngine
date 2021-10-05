#pragma once

#ifdef ML_PLATFORM_WINDOWS

extern ML::Application* ML::createApplication();

int main(int argc, char** argv) {
	ML::Log::init();
	ML_CORE_WARN("Initiliazed Log!");
	int a = 5;
	ML_INFO("Welcome! var={0}", a);
	ML::Log::GetClientLogger()->info("Hello!");
	auto app = ML::createApplication();
	app->run();
	delete app;
}

#endif
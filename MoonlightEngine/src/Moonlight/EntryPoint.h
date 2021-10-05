#pragma once

#ifdef ML_PLATFORM_WINDOWS

extern ML::Application* ML::createApplication();

int main(int argc, char** argv) {
	std::cout << "Welcome to Moonlight!" << std::endl;
	auto app = ML::createApplication();
	app->run();
	delete app;
}

#endif
#include "mlpch.h"
#include <Moonlight.h>

class Sandbox : public ML::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

ML::Application* ML::createApplication() {
	return new Sandbox();
}
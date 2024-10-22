#ifndef APPLICATION_H
#define APPLICATION_H

#include "Engine.h"

#include "Camera.h"

class Application {
public:
	Application() = default;
	~Application() = default;

	void run();
private:
	brayjl::Window m_window{ 1280, 720, "BrayJL Engine" };
};

#endif
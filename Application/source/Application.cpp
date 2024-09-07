#include "Application.h"

void Application::run() {
	while (!m_window.shouldClose()) {
		m_window.update();
	}
}
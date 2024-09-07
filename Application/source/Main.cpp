#include "Application.h"

#include <stdexcept>
#include <iostream>
#include <cstdint>

int main(void) {
	brayjl::Logger::initialize();

	Application application{};
	try {
		application.run();
	} catch (const std::exception& exception) {
		spdlog::error(exception.what());
		std::cin.get();

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
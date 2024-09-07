#include "Engine.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(void) {
	if (glfwInit() == GLFW_FALSE) {
		brayjl::print("Hello BrayJL! FAIL");
	} else {
		brayjl::print("Hello BrayJL!");
	}

	gladLoadGL();

	std::cin.get();

	return 0;
}
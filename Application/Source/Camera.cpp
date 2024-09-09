#include "Camera.h"

glm::mat4 Camera::getViewMatrix() const {
	return m_viewMatrix;
}

void Camera::update(const brayjl::Window& window, const float& deltaTime) {
	updateVectors();
	updatePosition(window, deltaTime);
	updateDirection(window, deltaTime);

	m_viewMatrix = glm::lookAt(
		m_position,
		m_position + m_front,
		m_up
	);
}

void Camera::updateVectors() {
	glm::vec3 front{
		std::cos(glm::radians(m_yaw)) * std::cos(glm::radians(m_pitch)),
		std::sin(glm::radians(m_pitch)),
		std::sin(glm::radians(m_yaw)) * std::cos(glm::radians(m_pitch))
	};

	m_front = glm::normalize(front);
	m_right = glm::normalize(glm::cross(m_front, m_up));
}

void Camera::updatePosition(const brayjl::Window& window, const float& deltaTime) {
	if (brayjl::InputHandler::getKeyDown(window, GLFW_KEY_W)) m_position += m_front * m_speed * deltaTime;
	if (brayjl::InputHandler::getKeyDown(window, GLFW_KEY_A)) m_position -= m_right * m_speed * deltaTime;
	if (brayjl::InputHandler::getKeyDown(window, GLFW_KEY_S)) m_position -= m_front * m_speed * deltaTime;
	if (brayjl::InputHandler::getKeyDown(window, GLFW_KEY_D)) m_position += m_right * m_speed * deltaTime;

	if (brayjl::InputHandler::getKeyDown(window, GLFW_KEY_Q)) m_position.y -= m_speed * deltaTime;
	if (brayjl::InputHandler::getKeyDown(window, GLFW_KEY_E)) m_position.y += m_speed * deltaTime;
}

void Camera::updateDirection(const brayjl::Window& window, const float& deltaTime) {
	if (brayjl::InputHandler::getKeyDown(window, GLFW_KEY_UP))		m_pitch += m_lookSpeed * deltaTime;
	if (brayjl::InputHandler::getKeyDown(window, GLFW_KEY_LEFT))	m_yaw -= m_lookSpeed * deltaTime;
	if (brayjl::InputHandler::getKeyDown(window, GLFW_KEY_RIGHT))	m_yaw += m_lookSpeed * deltaTime;
	if (brayjl::InputHandler::getKeyDown(window, GLFW_KEY_DOWN))	m_pitch -= m_lookSpeed * deltaTime;

	m_pitch = glm::clamp(m_pitch, -89.0f, 89.0f);
}
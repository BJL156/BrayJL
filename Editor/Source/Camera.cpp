#include "Camera.h"

void Camera::update(const brayjl::Window& window, const float& deltaTime) {
	updateVectors();
	updatePosition(window, deltaTime);
	updateDirection(window, deltaTime);
	updateZoom(deltaTime);

	m_viewMatrix = glm::lookAt(
		m_position,
		m_position + m_front,
		m_up
	);
}

glm::mat4 Camera::getViewMatrix() const {
	return m_viewMatrix;
}

float Camera::getFov() const {
	return m_fov;
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
	if (brayjl::InputHandler::isKeyDown(brayjl::Key::W)) m_position += m_front * m_speed * deltaTime;
	if (brayjl::InputHandler::isKeyDown(brayjl::Key::A)) m_position -= m_right * m_speed * deltaTime;
	if (brayjl::InputHandler::isKeyDown(brayjl::Key::S)) m_position -= m_front * m_speed * deltaTime;
	if (brayjl::InputHandler::isKeyDown(brayjl::Key::D)) m_position += m_right * m_speed * deltaTime;

	if (brayjl::InputHandler::isKeyDown(brayjl::Key::Q)) m_position.y -= m_speed * deltaTime;
	if (brayjl::InputHandler::isKeyDown(brayjl::Key::E)) m_position.y += m_speed * deltaTime;
}

void Camera::updateDirection(const brayjl::Window& window, const float& deltaTime) {
	if (brayjl::InputHandler::isKeyDown(brayjl::Key::UP))		m_pitch += m_lookSpeed * deltaTime;
	if (brayjl::InputHandler::isKeyDown(brayjl::Key::LEFT))		m_yaw -= m_lookSpeed * deltaTime;
	if (brayjl::InputHandler::isKeyDown(brayjl::Key::RIGHT))	m_yaw += m_lookSpeed * deltaTime;
	if (brayjl::InputHandler::isKeyDown(brayjl::Key::DOWN))		m_pitch -= m_lookSpeed * deltaTime;

	m_pitch = glm::clamp(m_pitch, -89.0f, 89.0f);
}

void Camera::updateZoom(const float& deltaTime) {
	if (brayjl::InputHandler::isKeyDown(brayjl::Key::Z)) m_fov = glm::clamp(m_fov - m_zoomSpeed * deltaTime, 1.0f, m_maxFov);
	if (brayjl::InputHandler::isKeyDown(brayjl::Key::X)) m_fov = glm::clamp(m_fov + m_zoomSpeed * deltaTime, 1.0f, m_maxFov);
}
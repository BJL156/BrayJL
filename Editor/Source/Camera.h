#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Platform/InputHandler.h"
#include "Platform/Window.h"
#include "Platform/InputCodes.h"

class Camera {
public:
	Camera() = default;
	~Camera() = default;

	void update(const brayjl::Window& window, const float& deltaTime);

	glm::mat4 getViewMatrix() const;
	float getFov() const;
private:
	void updateVectors();
	void updatePosition(const brayjl::Window& window, const float& deltaTime);
	void updateDirection(const brayjl::Window& window, const float& deltaTime);
	void updateZoom(const float& deltaTime);

	glm::vec3 m_up = { 0.0f, 1.0f, 0.0f };
	glm::vec3 m_front = { 0.0f, 0.0f, 0.0f };
	glm::vec3 m_right = { 0.0f, 0.0f, 0.0f };
	glm::vec3 m_position = { 0.0f, 0.0f, 0.0f };
	glm::mat4 m_viewMatrix = glm::mat4(1.0f);
	float m_speed = 2.5f;
	float m_lookSpeed = 50.0f;
	float m_zoomSpeed = 50.0f;
	float m_yaw = -90.0f;
	float m_pitch = 0.0f;
	float m_maxFov = 90.0f;
	float m_fov = m_maxFov;
};

#endif
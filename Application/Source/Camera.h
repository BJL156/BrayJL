#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Platform/InputHandler.h"
#include "Platform/Window.h"

class Camera {
public:
	Camera() = default;
	~Camera() = default;

	glm::mat4 getViewMatrix() const;

	void update(const brayjl::Window& window, const float& deltaTime);
private:
	void updateVectors();
	void updatePosition(const brayjl::Window& window, const float& deltaTime);
	void updateDirection(const brayjl::Window& window, const float& deltaTime);

	glm::vec3 m_up			= { 0.0, 1.0, 0.0 };
	glm::vec3 m_front		= { 0.0, 0.0, 0.0 };
	glm::vec3 m_right		= { 0.0, 0.0, 0.0 };
	glm::vec3 m_position	= { 0.0, 0.0, 0.0 };
	glm::mat4 m_viewMatrix	= glm::mat4(1.0);
	float m_speed = 2.5f;
	float m_lookSpeed = 50.0f;
	float m_yaw = -90.0;
	float m_pitch = 0.0;
};

#endif
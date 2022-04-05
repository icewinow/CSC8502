#include"Camera.h"
#include"Window.h"
#include<algorithm>
void Camera::UpdateCamera(float dt) {

	if (!autocamera) {
		pitch -= (Window::GetMouse()->GetRelativePosition().y);
		yaw -= (Window::GetMouse()->GetRelativePosition().x);

		pitch = std::min(pitch, 90.0f);
		pitch = std::max(pitch, -90.0f);

		if (yaw < 0) {
			yaw += 360.0f;

		}

		if (yaw > 360.0f) {
			yaw -= 360.0f;
		}

		Matrix4 rotation = Matrix4::Rotation(yaw, Vector3(0, 1, 0));
		Vector3 forward = rotation * Vector3(0, 0, -1);
		Vector3 right = rotation * Vector3(1, 0, 0);

		float speed = 1000.0f * dt;

		if (Window::GetKeyboard()->KeyDown(KEYBOARD_W)) {
			position += forward * speed;

		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_S)) {
			position -= forward * speed;

		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_A)) {
			position -= right * speed;

		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_D)) {
			position += right * speed;

		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_SHIFT)) {
			position.y += speed;

		}
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_SPACE)) {
			position.y -= speed;

		}
	}
	
	else {

		pitch = std::min(pitch, 90.0f);
		pitch = std::max(pitch, -90.0f);

		if (yaw < 0) {
			yaw += 360.0f;

		}

		if (yaw > 360.0f) {
			yaw -= 360.0f;
		}

		Matrix4 rotation = Matrix4::Rotation(yaw, Vector3(0, 1, 0));
		Vector3 forward = rotation * Vector3(0, 0, -1);
		Vector3 right = rotation * Vector3(1, 0, 0);

		float speed = 1000.0f * dt;
		if (position.x >= maxx )
		{
			gox = false;
			
		}
		else if (position.x <= minx) {
			gox = true;
			
		}
		if (position.z >= maxz)
		{
			goz = false;
		}
		else if (position.z <= minz) {
			goz = true;
		}

		if (gox)
		{
			position.x += speed;
			yaw = 180.0f;
			pitch = -45.0f;

		}
		else {
			position.x -= speed;
			yaw = 0.0f;
			pitch = -45.0f;
		}

		if (goz) {
			position.z += speed;
		}
		else {
			position.z -= speed;
		}

		

	}


}

Matrix4 Camera::BuildViewMatrix() {
	Matrix4 r1 = Matrix4::Rotation(-pitch, Vector3(1, 0, 0));
	Matrix4 r2 = Matrix4::Rotation(-yaw, Vector3(0, 1, 0));
	Matrix4 r3 = Matrix4::Translation(-position);
	Matrix4 r4 = r1 * r2 * r3;
	return Matrix4::Rotation(-pitch, Vector3(1, 0, 0)) *
		Matrix4::Rotation(-yaw, Vector3(0, 1, 0)) *
		Matrix4::Translation(-position);


}



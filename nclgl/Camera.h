#pragma once
#include"Matrix4.h"
#include"Vector3.h"

class Camera {
public:
	Camera(void) {
		yaw = 0.0f;
		pitch = 0.0f;

	}
	Camera(float pitch, float yaw, Vector3 position) {
		this->pitch = pitch;
		this->yaw = yaw;
		this->position = position;
		this->gox = true;
		this->goz = true;
		this->autocamera = true;

	}
	~Camera(void) {};

	void UpdateCamera(float dt = 1.0f);

	Matrix4 BuildViewMatrix();

	Vector3 GetPosition()const { return position; }
	void SetPosition(Vector3 val) { position = val; }

	float GetYaw()const { return yaw; }
	void SetYaw(float y) { yaw = y; }

	float GetPitch()const { return pitch; }
	void SetPitch(float p) { pitch = p; }

	void SetMinx(float v) { minx = v; }
	void SetMinz(float v) { minz = v; }
	void SetMaxx(float v) { maxx = v; }
	void SetMaxz(float v) { maxz = v; }

	void Togglecamera(){ autocamera = !autocamera; }



protected:
	float yaw;
	float pitch;
	Vector3 position;
	bool autocamera;
	bool gox;
	bool goz;
	float minx;
	float minz;
	float maxx;
	float maxz;

};

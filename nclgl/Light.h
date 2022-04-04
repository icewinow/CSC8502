#pragma once
#include"Vector4.h";
#include"Vector3.h";

class Light {
public:
	Light() { this->type = 0; }
	Light(const Vector3& position, const Vector4 colour, float radius) {
		this->position = position;
		this->colour = colour;
		this->radius = radius;
		this->type = 0;
	}
	~Light(void) {};

	Vector3 GetPosition()const { return position; }
	void SetPositon(const Vector3& val) { position = val; }

	float GetRadius()const { return radius; }
	void SetRadius(float val) { radius = val; }

	Vector4 GetColour()const { return colour; }
	void SetColour(const Vector4& val) { colour = val; }

	int GetType() const{ return type; }
	void SetType(const int val) { type = val; }

protected:
	Vector3 position;
	float radius;
	Vector4 colour;
	int type;
};
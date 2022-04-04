#pragma once
#include"Light.h"

class SpotLight : public Light {
public:
	SpotLight() { this->type = 1; };
	SpotLight::SpotLight(const Vector3& position, const Vector4 colour, float radius, const Vector3& Dirction, float Cutoff, float OuterCutoff) :
		Light(position, colour, radius) {
		this->Dirction = Dirction;
		this->Cutoff = Cutoff;
		this->OuterCutoff = OuterCutoff;
		this->type = 1;
	}
	~SpotLight(void) {};

	Vector3 GetDirction()const { return Dirction; }
	void SetDirction(const Vector3& val) { Dirction = val; }

	float GetCutoff()const { return Cutoff; }
	void SetCutoff(const float val) { Cutoff = val; }

	float GetOuterCutoff()const { return OuterCutoff; }
	void SetOuterCutoff(const float val) { OuterCutoff = val; }

protected:
	float Cutoff;
	float OuterCutoff;
	Vector3 Dirction;
};
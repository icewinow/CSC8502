#pragma once
#include"Light.h"

class DirctionLight : public Light {
public:

	DirctionLight() { this->type = 2; };
	DirctionLight(const Vector4 colour, const Vector3& Dirction) {
		this->colour = colour;
		this->Dirction = Dirction;
		this->type = 2;
	}

	Vector3 GetDirction()const { return Dirction; }
	void SetDirction(const Vector3& val) { Dirction = val; }

protected:
	Vector3 Dirction;


};
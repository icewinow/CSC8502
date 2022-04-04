#pragma once
#include"Matrix4.h"
#include"Matrix3.h"
#include"Matrix2.h"
#include"Mesh.h"
#include<vector>

class SceneNode {
public:
	SceneNode(Mesh* m = NULL, Vector4 colour = Vector4(1, 1, 1, 1));
	~SceneNode(void);

	void SetTransform(const Matrix4& matrix) { transform = matrix; };
	const Matrix4& GetTransform() const { return transform; };
	Matrix4 GetWorldTransform() const { return worldTransform; };

	Vector4 GetColour() const { return colour; };
	void SetColour(Vector4 c) { colour = c; };

	Vector3 GetModelScale() { return modelScale; };
	void SetModelScale(Vector3 s) { modelScale = s; };

	Mesh* GetMesh() const { return mesh; };
	void SetMesh(Mesh* m) { mesh = m; };

	float GetBoundingRadius()const { return boundingRadius; }
	void SetBoundingRadius(float f) { boundingRadius = f; }

	float GetCameraDistance() const { return distanceFromCamera; }
	void SetCameraDistance(float f) { distanceFromCamera = f; }

	void SetDiffuseTex(GLuint tex) { diffTex = tex; }
	GLuint GetDiffuseTex() const { return diffTex; }

	void SetNormalTex(GLuint tex) { normTex = tex; }
	GLuint GetNormalTex() const { return normTex; }

	static bool CompareByCameraDistance(SceneNode* a, SceneNode* b) {
		return(a->distanceFromCamera < b->distanceFromCamera) ? true : false;
	}

	void AddChild(SceneNode* s);

	virtual void Update(float dt);
	virtual void Draw(const OGLRenderer& r);

	std::vector<SceneNode*>::const_iterator GetChildIteratorStart() { return children.begin(); };
	std::vector<SceneNode*>::const_iterator GetChildIteratorEnd() { return children.end(); };

protected:
	SceneNode* parent;
	Mesh* mesh;
	Matrix4 worldTransform;
	Matrix4 transform;
	Vector3 modelScale;
	Vector4 colour;
	std::vector<SceneNode*> children;
	float boundingRadius;
	float distanceFromCamera;
	GLuint diffTex;
	GLuint normTex;

};

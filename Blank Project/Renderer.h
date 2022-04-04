#pragma once
#include"../nclgl//OGLRenderer.h"
#include"../nclgl/Frustum.h"
#include"../nclgl/SceneNode.h"
#include"../nclgl/Camera.h"

class Camera;
class Mesh;
class SceneNode;
class HeightMap;

class Renderer : public OGLRenderer {
public:
	Renderer(Window& parent);
	~Renderer(void);

	void RenderScene() override;
	void UpdateScene(float de) override;
	float GetIntensity() { return intensity; }
	void Setintensity(float i) { intensity = i; }

	void ToggleMultipleLight() { MultipleLight = !MultipleLight; }
	void ToggleCamera() { camera->Togglecamera(); }

protected:
	void FillBuffers();
	void DrawPointLights();
	void DrawSkybox();
	void CombineBuffers();
	void DrawWater();
	void GenerateScreenTexture(GLuint& into, bool depth = false);

	void BuildNodeLists(SceneNode* from);
	void SortNodeLists();
	void ClearNodeLists();
	void DrawNodes();
	void DrawNode(SceneNode* n);

	Shader* sceneShader;
	Shader* pointlightShader;
	Shader* combineShader;
	Shader* skyboxShader;
	Shader* reflectShader;

	GLuint bufferFBO;
	GLuint bufferColourTex;
	GLuint bufferNormalTex;
	GLuint bufferDepthTex;

	GLuint pointLightFBO;
	GLuint lightDiffuseTex;
	GLuint lightSpecularTex;

	SceneNode* root;
	HeightMap* heightMap;
	Light* pointLights;
	SpotLight* spotLights;
	DirctionLight* dl;
	Light* l;
	Mesh* sphere;
	Mesh* quad;
	Mesh* stone;
	Mesh* water;
	Mesh* skybox;
	Camera* camera;

	GLuint waterTex;
	GLuint stoneTex;
	GLuint stoneBump;
	GLuint earthTex;
	GLuint earthBump;
	GLuint earthTex2;
	GLuint earthBump2;
	GLuint cubeMap;
	GLuint texture;
	GLuint normal;

	Frustum frameFrustum;

	vector<SceneNode*> transparentNodeList;
	vector<SceneNode*> nodeList;

	float waterRotate;
	float waterCycle;
	float intensity;
	bool MultipleLight;
	bool autocamera;

};
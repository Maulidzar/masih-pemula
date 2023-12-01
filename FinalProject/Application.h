#pragma once

#include "RenderEngine.h"
#include "Cube.h"
#include "Shader.h"
#include "Texture.h"
#include "Camera.h"

class Application :
    public RenderEngine
{
public:
    Application();
    ~Application();
private:
	Shader *shader;
	Texture *cubeDiffTex, *cubeSpecTex, *cubeWhiteTex, *cubeMerahTex, *cubeLantaiTex, *cubeVasTex, *cubeBungaTex, *cubeTVTex, *cubeACTex;
	Cube *cube, *cubeWhite, *cubeMerah, *cubeLantai, *cubeDinding, *cubeSampingAtas, *cubeSampingBawah, *cubeSampingBawah2, *cubeDepanAtas, *cubeDepanBawah, *cubeDepanBawah2, *cubeVas, *cubeTangkai, *cubeBunga, *cubeTV, *cubeAC, *cubeLampu;
	Camera *camera;
	float angle = 0;
	glm::vec3 viewPos;
	void setupPerspective();
	void setupCamera();
	void setupLighting(); 
	virtual void Init();
	virtual void DeInit(); 
	virtual void Update(double deltaTime);
	virtual void Render();
	virtual void ProcessInput(GLFWwindow* window);
	std::vector<glm::vec3> blockPositions;
};


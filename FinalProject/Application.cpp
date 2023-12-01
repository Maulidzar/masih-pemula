#include "Application.h"

Application::Application()
{

}

Application::~Application()
{
}

void Application::setupPerspective()
{
	// Pass perspective projection matrix
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 100.0f);
	shader->setMat4("projection", projection);
}

void Application::setupCamera()
{
	// LookAt camera (position, target/direction, up)
	viewPos = glm::vec3(0, 2, 3);
	glm::mat4 view = glm::lookAt(viewPos, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	shader->setMat4("view", view);
}

void Application::setupLighting()
{
	// set lighting attributes
	glm::vec3 lightPos = glm::vec3( 0, 1, 0);
	shader->setVec3("lightPos", lightPos);
	shader->setVec3("viewPos", viewPos);
	glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
	shader->setVec3("lightColor", lightColor);
}

void Application::Init()
{
	// Build a lighting map shader
	shader = new Shader("texturedCube.vert", "texturedCube.frag");
	shader->Init();
	// Create cube diffuse texture and specular texture
	cubeDiffTex = new Texture("crate_diffusemap.png");
	cubeDiffTex->Init();
	cubeSpecTex = new Texture("crate_specularmap.png");
	cubeSpecTex->Init();
	cubeWhiteTex = new Texture("grey.png");
	cubeWhiteTex->Init();
	cubeMerahTex = new Texture("red.jpg");
	cubeMerahTex->Init();
	cubeLantaiTex = new Texture("lantai.jpg");
	cubeLantaiTex->Init();
	cubeVasTex = new Texture("vas.png");
	cubeVasTex->Init();
	cubeBungaTex = new Texture("bunga.png");
	cubeBungaTex->Init();
	cubeTVTex = new Texture("tv.png");
	cubeTVTex->Init();
	cubeACTex = new Texture("ac2.png");
	cubeACTex->Init();
	// Create instance of cube
	cube = new Cube(shader, cubeDiffTex, cubeSpecTex);
	cubeWhite = new Cube(shader, cubeWhiteTex, cubeSpecTex);
	cubeMerah = new Cube(shader, cubeMerahTex, cubeWhiteTex);
	cubeLantai = new Cube(shader, cubeLantaiTex, cubeWhiteTex);
	cubeDinding = new Cube(shader, cubeLantaiTex, cubeWhiteTex);
	cubeSampingAtas = new Cube(shader, cubeLantaiTex, cubeWhiteTex);
	cubeSampingBawah = new Cube(shader, cubeLantaiTex, cubeWhiteTex);
	cubeSampingBawah2 = new Cube(shader, cubeLantaiTex, cubeWhiteTex);
	cubeDepanAtas = new Cube(shader, cubeLantaiTex, cubeWhiteTex);
	cubeDepanBawah = new Cube(shader, cubeLantaiTex, cubeWhiteTex);
	cubeDepanBawah2 = new Cube(shader, cubeLantaiTex, cubeWhiteTex);
	cubeVas = new Cube(shader, cubeVasTex, cubeWhiteTex);
	cubeTangkai = new Cube(shader, cubeLantaiTex, cubeWhiteTex);
	cubeBunga = new Cube(shader, cubeBungaTex, cubeWhiteTex);
	cubeTV = new Cube(shader, cubeTVTex, cubeWhiteTex);
	cubeAC = new Cube(shader, cubeACTex, cubeWhiteTex);
	cubeLampu = new Cube(shader, cubeWhiteTex, cubeSpecTex);
	cube->Init();
	cubeWhite->Init();
	cubeMerah->Init();
	cubeLantai->Init();
	cubeDinding->Init();
	cubeSampingBawah->Init();
	cubeSampingAtas->Init();
	cubeSampingBawah2->Init();
	cubeDepanBawah->Init();
	cubeDepanAtas->Init();
	cubeDepanBawah2->Init();
	cubeVas->Init();
	cubeTangkai->Init();
	cubeBunga->Init();
	cubeTV->Init();
	cubeAC->Init();
	cubeLampu->Init();
	cube->SetScale(0.2f, 0.2f, 0.2f);
	cubeWhite->SetScale(5.0f, 0.05f, 5.0f);
	cubeMerah->SetScale(0.2f, 0.2f, 0.2f);
	cubeLantai->SetScale(10.0f, 0.1f, 10.0f);
	cubeDinding->SetScale(10.0f, 5.0f, 0.1f);
	cubeSampingAtas->SetScale(0.1f, 2.5f, 10.0f);
	cubeSampingBawah->SetScale(0.1f, 2.5f, 5.0f);
	cubeSampingBawah2->SetScale(0.1f, 2.5f, 3.5f);
	cubeDepanAtas->SetScale(10.0f, 2.5f, 0.1f);
	cubeDepanBawah->SetScale(7.0f, 2.5f, 0.1f);
	cubeDepanBawah2->SetScale(1.5f, 2.5f, 0.1f);
	cubeVas->SetScale(0.2f, 0.2f, 0.2f);
	cubeTangkai->SetScale(0.025f, 0.1f, 0.025f);
	cubeBunga->SetScale(0.08f, 0.08f, 0.08f);
	cubeTV->SetScale(2.0f, 1.0f, 0.1f);
	cubeAC->SetScale(2.0f, 0.5f, 0.5f);
	cubeLampu->SetScale(0.2f, 0.2f, 0.2f);
	camera = new Camera();
	camera->Init(window);

	// setup perspective 
	setupPerspective();
	// setup camera
	setupCamera();
	// setup lighting
	setupLighting();
}

void Application::DeInit()
{
	delete cube;
}

void Application::Update(double deltaTime)
{
	angle += (float)((deltaTime * 1.5f) / 1000);
	cube->SetRotation(0, 0, 1, 0);
	cubeWhite->SetRotation(0, 0, 1, 0);
	cubeMerah->SetRotation(0, 0, 1, 0);
	cubeLantai->SetRotation(0, 0, 1, 0);
	cubeDinding->SetRotation(0, 0, 1, 0);
	cubeSampingBawah->SetRotation(0, 0, 1, 0);
	cubeSampingBawah2->SetRotation(0, 0, 1, 0);
	cubeSampingAtas->SetRotation(0, 0, 1, 0);
	cubeDepanBawah->SetRotation(0, 0, 1, 0);
	cubeDepanBawah2->SetRotation(0, 0, 1, 0);
	cubeDepanAtas->SetRotation(0, 0, 1, 0);
	cubeVas->SetRotation(0, 0, 1, 0);
	cubeTangkai->SetRotation(0, 0, 1, 0);
	cubeBunga->SetRotation(0, 0, 1, 0);
	cubeTV->SetRotation(0, 0, 1, 0);
	cubeAC->SetRotation(0, 0, 1, 0);
	cubeLampu->SetRotation(0, 0, 1, 0);
}

void Application::Render()
{
	glViewport(0, 0, this->screenWidth, this->screenHeight);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_DEPTH_TEST);
	// Camera
	shader->setMat4("view", camera->GetViewMatrix());
	shader->setMat4("projection", camera->GetProjectionMatrix(this->screenWidth, this->screenHeight));
 	
	// Dinding Belakang
	cubeDinding->SetPosition(0, 0.45, -49.5);
	cubeDinding->Draw();

	// Dinding Depan Atas
	cubeDepanAtas->SetPosition(0, 1.4, 49.5);
	cubeDepanAtas->Draw();

	// Dinding Depan Bawah 1
	cubeDepanBawah->SetPosition(-0.21, 0.4, 49.5);
	cubeDepanBawah->Draw();

	// Dinding Depan Bawah 2
	cubeDepanBawah2->SetPosition(2.8, 0.4, 49.5);
	cubeDepanBawah2->Draw();

	// Dinding Kanan Atas
	cubeSampingAtas->SetPosition(50, 1.4, 0);
	cubeSampingAtas->Draw();

	// Dinding Kanan Bawah 1
	cubeSampingBawah->SetPosition(50, 0.4, -0.5);
	cubeSampingBawah->Draw();

	// Dinding Kanan Bawah 2
	cubeSampingBawah2->SetPosition(50, 0.4, 0.93);
	cubeSampingBawah2->Draw();

	// Dinding Kiri Atas
	cubeSampingAtas->SetPosition(-50, 1.4, 0);
	cubeSampingAtas->Draw();

	// Dinding Kiri Bawah 1
	cubeSampingBawah->SetPosition(-50, 0.4, -0.5);
	cubeSampingBawah->Draw();

	// Dinding Kiri Bawah 2
	cubeSampingBawah2->SetPosition(-50, 0.4, 0.93);
	cubeSampingBawah2->Draw();

	// Dinding Kiri Atas
	cubeSampingAtas->SetPosition(-50, 1.4, 0);
	cubeSampingAtas->Draw();

	// Lantai Kayu
	cubeLantai->SetPosition(0, -2.2, 0);
	cubeLantai->Draw();

	// Atap
	cubeLantai->SetPosition(0, 47, 0);
	cubeLantai->Draw();

	// Ambal
	cubeWhite->SetPosition(0, -2.5, 0);
	cubeWhite->Draw();

	// Bagian atas meja 
	for (int i = 0; i < 9; i++) {
		cube->SetPosition(-4 + i * 1, 3, 1);
		cube->Draw();
	}

	for (int i = 0; i < 9; i++) {
		cube->SetPosition(-4 + i * 1, 3, 2);
		cube->Draw();
	}

	for (int i = 0; i < 9; i++) {
		cube->SetPosition(-4 + i * 1, 3, 3);
		cube->Draw();
	}

	for (int i = 0; i < 9; i++) {
		cube->SetPosition(-4 + i * 1, 3, 4);
		cube->Draw();
	}

	for (int i = 0; i < 9; i++) {
		cube->SetPosition(-4 + i * 1, 3, 5);
		cube->Draw();
	}

	// Bagian kaki meja depan
	for (int i = 0; i < 3; i++) {
		cube->SetPosition(-4, 0 + i * 1, 5);
		cube->Draw();
	}

	for (int i = 0; i < 3; i++) {
		cube->SetPosition(4, 0 + i * 1, 5);
		cube->Draw();
	}

	// Bagian kaki meja belakang
	for (int i = 0; i < 3; i++) {
		cube->SetPosition(-4, 0 + i * 1, 1);
		cube->Draw();
	}

	for (int i = 0; i < 3; i++) {
		cube->SetPosition(4, 0 + i * 1, 1);
		cube->Draw();
	}

	// Lampu Putih

	cubeLampu->SetPosition(0, 22.5, 3);
	cubeLampu->Draw();

	// Vas

	cubeVas->SetPosition(0, 4, 3);
	cubeVas->Draw(); 

	// Tangkai

	cubeTangkai->SetPosition(0, 9.5, 23.7);
	cubeTangkai->Draw();

	// Bunga
	
	cubeBunga->SetPosition(0, 13, 7.4);
	cubeBunga->Draw();

	// TV

	cubeTV->SetPosition(0, 1.5, 48.5);
	cubeTV->Draw();

	// AC

	cubeAC->SetPosition(0, 7, -9.35);
	cubeAC->Draw();

	// Punya Gideon

	//Kerangka belakang
	for (int i = 0; i < 9; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 1, -7);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 9; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 2, -7);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 9; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 3, -7);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 9; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 4, -7);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 9; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 5, -7);
		cubeMerah->Draw();
	}
	//Kerangka bawah
	for (int i = 0; i < 9; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 1, -6);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 9; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 1, -5);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 9; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 1, -4);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 9; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 1, -3);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 9; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 1, -2	);
		cubeMerah->Draw();
	}
	//Kerangka bawah tapi tumpukkan ke2
	for (int i = 0; i < 9; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 2, -6);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 9; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 2, -5);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 9; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 2, -4);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 9; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 2, -3);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 9; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 2, -2);
		cubeMerah->Draw();
	}
	//kaki kiri depan
	for (int i = 0; i < 1; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 0, -2);
		cubeMerah->Draw();
	}
	//kaki kanan depan
	for (int i = 0; i < 1; i++) {
		cubeMerah->SetPosition(4 + i * 1, 0, -2);
		cubeMerah->Draw();
	}

	//kaki kiri belakang
	for (int i = 0; i < 1; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 0, -7);
		cubeMerah->Draw();
	}
	//kaki kanan belakang	
	for (int i = 0; i < 1; i++) {
		cubeMerah->SetPosition(4 + i * 1, 0, -7);
		cubeMerah->Draw();
	}

	//arm rest kiri
	for (int i = 0; i < 1; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 3, -6);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 1; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 3, -5);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 1; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 3, -4);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 1; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 3, -3);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 1; i++) {
		cubeMerah->SetPosition(-4 + i * 1, 3, -2);
		cubeMerah->Draw();
	}
	//arm rest kanan
	for (int i = 0; i < 1; i++) {
		cubeMerah->SetPosition(4 + i * 1, 3, -6);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 1; i++) {
		cubeMerah->SetPosition(4 + i * 1, 3, -5);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 1; i++) {
		cubeMerah->SetPosition(4 + i * 1, 3, -4);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 1; i++) {
		cubeMerah->SetPosition(4 + i * 1, 3, -3);
		cubeMerah->Draw();
	}
	for (int i = 0; i < 1; i++) {
		cubeMerah->SetPosition(4 + i * 1, 3, -2);
		cubeMerah->Draw();
	}

	glDisable(GL_DEPTH_TEST);

}

void Application::ProcessInput(GLFWwindow* window)
{
	camera->ProcessInput(window, screenHeight, screenWidth, blockPositions);

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


int main(int argc, char** argv) {
	Application app = Application();
	app.Start("Ruang Keluarga", 
		1280, 720, 
		false, 
		false);
}
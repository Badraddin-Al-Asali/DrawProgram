//STL library
#include<iostream>
#include <string>

#include<algorithm>

#include "OpenGLHeader.h"

#include "CreateShaderID.h"
#include "FragmentShader.h"
#include "VertexShader.h"
#include "CreateShaderProgram.h"
#include "DrawBox.h"
#include "BindVertex.h"

#include "Pixels.h"
#include "Line.h"

using namespace std;

bool onHoldM1(false), pressL(false);

int x(0), y(0), pressX(0), pressY(0), action(0);

Pixels* pixel;

vector<Line> lines;

int main() {
	lines.reserve(25);
	//prototype
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void processInput(GLFWwindow *window);
	void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

	//winodw size
	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 600;

	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);
	
	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//create shaders
	const CreateShaderID createShaderID;
	const Fragment fragment("shader.fs", createShaderID);
	const Vertix vertix("shader.vs", createShaderID);
	const CreateShaderProgram theShader(fragment, vertix);

	//The Draw Box
	const DrawBox drawBox;
	//bindVertices(DrawBox)
	const BindVertex bindVertex(drawBox.getBoxCoor(), drawBox.getBoxSize(), drawBox.getBoxByte());

	Pixels pixels;
	pixel = &pixels;
	theShader.setInt("textures", 0);

	float timeValue(0.0f), lastTime(glfwGetTime());
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, pixels.getTexture());
	theShader.use();
	glBindVertexArray(bindVertex.getVAO());

	while (!glfwWindowShouldClose(window))
	{
		//input
		processInput(window);
		// render
		// ------

		glDrawArrays(GL_TRIANGLES, 0, 6);
		glfwSwapBuffers(window);
		glfwPollEvents();

		//timeValue = glfwGetTime();
		//if (timeValue - lastTime >= 1.0) {
			//system("cls");
			//cout << "X: " << (int)x << " Y: " << (int)y << endl;
			//lastTime += 1.0;
		//}
		
		Sleep(50);
	}

	glfwTerminate();

	system("pause");
	return 0;
}
bool start(true);
int selectLine(-1);
void processInput(GLFWwindow *window) {
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS) {
		if (!onHoldM1) {
			pressX = x;
			pressY = y;
		}
		onHoldM1 = true;
	}
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_RELEASE && onHoldM1) {
		onHoldM1 = false;
		switch (action)
		{
		case 0:
			lines.push_back(Line(x, y, pressX, pressY));
			lines.back().render(pixel);
			break;
		case 1:
			if (selectLine == -1) {
				find_if(lines.begin(), lines.end(), [](Line line) {
					++selectLine;
					if (line.onVector_Start(x, y)) {
						start = true;
						cout << "Vector Start Selected..." << endl;
						return true;
					}
					else if (line.onVector_End(x, y)) {
						start = false;
						cout << "Vector End Selected..." << endl;
						return true;
					}
					return false;
				});
			}
			else {
				if (start) {
					lines[selectLine].unRender(pixel);
					lines[selectLine].editVector_Start(x, y);
					lines[selectLine].render(pixel);
					cout << "Postion Updated For Vector Start..." << endl;
					
				}
				else {
					lines[selectLine].unRender(pixel);
					lines[selectLine].editVector_End(x, y);
					lines[selectLine].render(pixel);
					cout << "Postion Updated For Vector End..." << endl;
				}
				selectLine = -1;
			}
			break;
		}
	}
	if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) {
		pressL = true;
	}
	else if (glfwGetKey(window, GLFW_KEY_L) == GLFW_RELEASE && pressL) {
		switch (action)
		{
		case 0:
			cout << "Switched to Edit mode..." << endl;
			action = 1;
			break;
		case 1:
			cout << "Switched to Draw mode..." << endl;
			action = 0;
			break;
		}
		pressL = false;
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	//change window size
	glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
	//x = (xpos / 400) - 1;
	//y = (ypos / 300) - 1;
	x = (int)xpos;
	y = 599 - (int)ypos;
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	
}
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
int g_window_size_x = 640;
int g_window_size_y = 480;

void glfwWindowSizeCallback(GLFWwindow* window, int width, int height) 
{
    g_window_size_x = width;
    g_window_size_y = height;
    glViewport(0, 0, g_window_size_x, g_window_size_y);
}

void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) 
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
        
    }
}
int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "glfwInit failed" << std::endl;
        return -1;
    }
        

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(g_window_size_x, g_window_size_y, "OpenGL test", NULL, NULL);
    if (!window)
    {
        std::cout << "glfwCreateWindow failed" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(window, glfwWindowSizeCallback);
    glfwSetKeyCallback(window, glfwKeyCallback);


    /* Make the window's context current */
    glfwMakeContextCurrent(window);
	if (!gladLoadGL())
	{
		std::cout<< "Can't load Glad library"<<std::endl;
		return -1;
	}
	
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION)<<std::endl;
    
	
	glClearColor(1,1,0,1);
	
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
#include <cstdlib>
#include <ios>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Error function for GLFW
void GLFWErrorCallback(int code, const char* description)
{
    std::cerr << "Error " << "0x" << std::hex << code << ':' << description << "\n";
}

// Error function for OpenGL
void GLAPIENTRY
MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam )
{
    std::cerr << "GL CALLBACK:" << ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ) <<
        "type = 0x" << type <<
        ", severity = 0x" << severity <<
        ", message =" << message << "\n";
}

// Entry point
int main(void)
{

    glfwSetErrorCallback(GLFWErrorCallback);
   
    // Initialization of glfw.
    if (!glfwInit())
    {
        std::cin.get();

        return EXIT_FAILURE;
    }

    // Create a window
    glfwWindowHint(GLFW_RESIZABLE, false);
    auto window = glfwCreateWindow(800, 600, "Hello Triangle", nullptr, nullptr);
    if (window == nullptr)
    {

        glfwTerminate();

        std::cin.get();

        return EXIT_FAILURE;
    }

    //Set the OpenGL context
    glfwMakeContextCurrent(window);

    GLenum error = glewInit();
    if (error != GLEW_OK)
    {
        std::cerr << "GLEW intialization failure:" << glewGetErrorString(error) << "\n";
        std::cin.get();

        glfwTerminate();

        return EXIT_FAILURE;
    }

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(MessageCallback, 0);

    glClearColor(0.5f, 0.0f, 0.0f, 1.0f);

    // Main loop
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        // Exit the loop if escape is pressed
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) break;
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}

#include <cstdlib>
#include <ios>
#include <iostream>
#include <GLFW/glfw3.h>

// Error function for GLFW
void GLFWErrorCallback(int code, const char* description)
{
    std::cerr << "Error " << "0x" << std::hex << code << ':' << description << "\n";
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

    // Main loop
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Exit the loop if escape is pressed
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) break;
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}

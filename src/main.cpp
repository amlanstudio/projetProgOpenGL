#include "App.hpp"
#include "Window.hpp"

static App& get_app(GLFWwindow* window) {
    return *reinterpret_cast<App*>(glfwGetWindowUserPointer(window));
}

int main() {
    // Initialize the library
    if (!glfwInit()) {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
#ifdef __APPLE__
    // We need to explicitly ask for a 3.3 context on Mac
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Les Cassoulettes", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Intialize glad (loads the OpenGL functions)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        return -1;
    }

    // Create the App
    App app;

    // Hook user inputs to the App
    glfwSetWindowUserPointer(window, reinterpret_cast<void*>(&app));
    
    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        get_app(window).key_callback(key, scancode, action, mods);
    });
    glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
        get_app(window).mouse_button_callback(button, action, mods);
    });
    glfwSetScrollCallback(window, [](GLFWwindow* window, double xoffset, double yoffset) {
        get_app(window).scroll_callback(xoffset, yoffset);
    });
    glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos) {
        get_app(window).cursor_position_callback(xpos, ypos);
    });
    glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        get_app(window).size_callback(width, height);
    });

    int xpos, ypos;
    glfwGetWindowPos(window, &xpos, &ypos);
    app.window_position_callback(xpos, ypos);

    // Force call the size_callback of the app to set the right viewport and projection matrix
    {
        int width, height;
        glfwGetWindowSize(window, &width, &height);
        app.size_callback(width, height);
    }

    // Loop until the user closes the window
    while (app.currentState != State::Quit && !glfwWindowShouldClose(window)) {
        glfwGetWindowPos(window, &xpos, &ypos);
        app.window_position_callback(xpos, ypos);
        
        app.Update();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        #ifdef __APPLE__
            static bool macMoved = false;

            if(!macMoved) {
                int x, y;
                glfwGetWindowPos(window, &x, &y);
                glfwSetWindowPos(window, ++x, y);
                macMoved = true;
            }
        #endif

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
#include "App.hpp"
#include "GLFW/glfw3.h"

#include <glm/glm/glm.hpp>
App::App(int window_width, int window_height)
{
    size_callback(window_width, window_height);
}

void App::render()
{
    glClearColor(1.f, 0.5f, 0.5f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    glm::vec2 test = glm::vec2(1,2);

    glm::vec2 test2 = 2.f * test - 1.f;
}

void App::key_callback(int /*key*/, int /*scancode*/, int /*action*/, int /*mods*/)
{
}

void App::mouse_button_callback(int /*button*/, int /*action*/, int /*mods*/)
{
}

void App::scroll_callback(double /*xoffset*/, double /*yoffset*/)
{
}

void App::cursor_position_callback(double /*xpos*/, double /*ypos*/)
{
}

void App::size_callback(int width, int height)
{
    _width  = width;
    _height = height;
}
#pragma once
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include <glm/glm.hpp>
#include <string>

#include "Niveau.hpp"

class App {
public:
    App();
    App(float viewSize);
    void Update();
    
    // callbacks users input
    void key_callback(int key, int scancode, int action, int mods);
    void mouse_button_callback(int button, int action, int mods);
    void scroll_callback(double xoffset, double yoffset);
    void cursor_position_callback(double xpos, double ypos);
    void size_callback(int width, int height);

private:
    void LoadImage(const std::string& imagePath); 
    void Render();
    glm::vec2 rotateVec2(const glm::vec2& vec, const glm::vec2& center, const float& angle);

    int _width;
    int _height;
    double _previousTime;

    bool pressed[349];

    GLuint _textureId;

    float _imageAngle;
    float _viewSize;

    std::vector<Niveau *> levels;
};
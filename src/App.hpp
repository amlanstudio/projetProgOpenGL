#pragma once
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include <glm/glm.hpp>
#include <string>

#include "Niveau.hpp"

enum class State{
    Homepage,
    Game,
    Rules,
    Credits,
    GameOver,
    WellDone,
    Quit
};

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
    void window_position_callback(int xpos, int ypos);

    State currentState;

private:
    void LoadImage(const std::string& imagePath, int currentImage); 
    void Render();
    glm::vec2 rotateVec2(const glm::vec2& vec, const glm::vec2& center, const float& angle);

    int _width;
    int _height;
    int _positionX = 0;
    int _positionY = 0;
    double _previousTime;

    bool pressed[349];
    bool mousePressed = false;
    int scroll = 0;
    glm::vec2 cursorPosition;

    GLuint _textureId[21];

    float _imageAngle;
    float _viewSize;

    std::vector<Niveau *> levels;
    int currentLevel = 0;
};

void initLevel(Niveau * level, std::vector<Rectangle> players, std::vector<Rectangle> map, float gravity, std::vector<Rectangle> finalPositionPlayers);
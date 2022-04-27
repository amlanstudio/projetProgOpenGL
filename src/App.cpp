#include "App.hpp"

#include <iostream>
#include <string>

#include "GLFW/glfw3.h"
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>

#include "helpers/RootDir.hpp"

#include "Formes.hpp"
#include "Niveau.hpp"
#include "Variables.hpp"

App::App() : _previousTime(0.0), _imageAngle(0.0f), _width(WIDTH), _height(HEIGHT) {

    // Generate texture
    glGenTextures(1, &_textureId);
    glBindTexture(GL_TEXTURE_2D, _textureId);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    // load and generate the texture
    int width, height, nrChannels;
    // tips found here for absolut ressources path: https://shot511.github.io/2018-05-29-how-to-setup-opengl-project-with-cmake/
    std::string imagePath = std::string(ROOT_DIR) + "res/poulpile.jpg";
    unsigned char *data = stbi_load(imagePath.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}

void App::Update() {

    double currentTime = glfwGetTime();
    double elapsedTime = currentTime - _previousTime;
    _previousTime = currentTime;
    
    // update imageAngle (use elapsedTime to update without being dependent on the frame rate)
    _imageAngle = fmod(_imageAngle + 10.0f * (float)elapsedTime, 360.0f);

    int direction = this->Controls(this->keyPressed);
            
    niv1.controls(direction);
    niv1.collision();

    this->keyPressed = 0;

    Render();
}

void App::Render() {
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    // Set up orphographic projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, _width, _height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    const glm::vec2 halfSize(_width/2.f, _height/2.f);


    // Exemple d'un rectangle
        // ici on trace le rectangle
        // test.draw();

    //Exemple d'un niveau
        // ici on pense bien à dessiner tous les personnages
        niv1.drawPlayers();
        niv1.drawMap();
}

int App::Controls(int scancode){
    // scancode haut : H
    // scancode bas : P
    // scancode gauche : K
    // scancode droite : M
    // scancode TAB : 15

    int direction;
    switch (scancode)
    {
    case 331:
        direction = -1;
        break;
    case 333:
        direction = 1;
        break;
    case 15:
        direction = 9;
        break;
    
    default:
        direction = 0;
        break;
    }

    return direction;
}

void App::key_callback(int key, int scancode, int action, int mods) {
    std::cout << scancode << " was " << action << std::endl;

    if(action == 1 || action == 2) this->keyPressed=scancode;
}

void App::mouse_button_callback(int /*button*/, int /*action*/, int /*mods*/) {
}

void App::scroll_callback(double /*xoffset*/, double /*yoffset*/) {
}

void App::cursor_position_callback(double /*xpos*/, double /*ypos*/) {
}

void App::size_callback(int width, int height) {
    _width  = width;
    _height = height;

    // make sure the viewport matches the new window dimensions
    glViewport(0, 0, _width, _height);
}

glm::vec2 App::rotateVec2(const glm::vec2& vec, const glm::vec2& center, const float& angle) {
    return glm::rotate(vec-center,  glm::radians(angle))+center;
}
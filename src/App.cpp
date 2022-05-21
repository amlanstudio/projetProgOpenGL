#include "App.hpp"

#include <iostream>
#include <string>

#include "GLFW/glfw3.h"
// #include "glad/glad.h"
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>

#include "helpers/RootDir.hpp"

#include "Formes.hpp"
#include "Niveau.hpp"
#include "Variables.hpp"
#include "Homepage.hpp"
#include "Rules.hpp"
#include "GameOver.hpp"
#include "WellDone.hpp"
#include "Credits.hpp"


int translateY = -95;

void initLevel(Niveau * level, std::vector<Rectangle> players, std::vector<Rectangle> map, float gravity, std::vector<Rectangle> finalPositionPlayers){
    // Initialisation du niveau
    // Level
    level->initNiveau(players, map, gravity, finalPositionPlayers);
};

App::App(): App(2.0f) {
}

App::App(float viewSize) : _previousTime(0.0), _imageAngle(0.0f), _viewSize(viewSize), currentState(State::Homepage) {

    const int nbImages = 19;

    // tips found here for absolut ressources path: https://shot511.github.io/2018-05-29-how-to-setup-opengl-project-with-cmake/
    const std::string imagePath[nbImages] = {
        std::string(ROOT_DIR) + "res/images/home_fond.png", //0
        std::string(ROOT_DIR) + "res/buttons/befstart_btn.png", //1
        std::string(ROOT_DIR) + "res/buttons/befcredits_btn.png", //2
        std::string(ROOT_DIR) + "res/buttons/befrules_btn.png", //3
        std::string(ROOT_DIR) + "res/buttons/befquit_btn.png", //4
        std::string(ROOT_DIR) + "res/buttons/btn_hovstart.png", //5
        std::string(ROOT_DIR) + "res/buttons/hovcredits_btn.png", //6
        std::string(ROOT_DIR) + "res/buttons/hovrules_btn.png",//7
        std::string(ROOT_DIR) + "res/buttons/hovquit_btn.png",//8
        std::string(ROOT_DIR) + "res/images/bg_rules.png",//9
        std::string(ROOT_DIR) + "res/buttons/befbtnback.png",//10
        std::string(ROOT_DIR) + "res/buttons/befbtnno.png",//11
        std::string(ROOT_DIR) + "res/buttons/hovbtnback.png",//12
        std::string(ROOT_DIR) + "res/buttons/hovbtnno.png",//13
        std::string(ROOT_DIR) + "res/buttons/befbtnyes.png",//14
        std::string(ROOT_DIR) + "res/buttons/hovbtnyes.png",//15
        std::string(ROOT_DIR) + "res/images/gameover.png",//16
        std::string(ROOT_DIR) + "res/images/welldone.png",//17
        std::string(ROOT_DIR) + "res/images/credits.png"//18
        };

    glGenTextures(nbImages, _textureId);
    for (int i = 0; i < nbImages; i++)
    {
        LoadImage(imagePath[i], i);
    }

    glBindTexture(GL_TEXTURE_2D, 0);

    for (size_t i = 0; i < 349; i++)
    {
        this->pressed[i] = false;
    }

    initLevel(&level1, playersLvl1, mLvl1, 0.1f, finalPosition);
    this->levels = {&level1};
}

void App::LoadImage(const std::string& imagePath, int currentImage) {
    // Generate texture
    // glGenTextures(1, _textureId);
    glBindTexture(GL_TEXTURE_2D, _textureId[currentImage]);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    // load and generate the texture
    int width, height, nrChannels;
    
    unsigned char *data = stbi_load(imagePath.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture number : " << currentImage << std::endl;
    }
    stbi_image_free(data);
}

void App::Update() {

    double currentTime = glfwGetTime();
    double elapsedTime = currentTime - _previousTime;
    _previousTime = currentTime;
    
    // update imageAngle (use elapsedTime to update without being dependent on the frame rate)
    // _imageAngle = fmod(_imageAngle + 10.0f * (float)elapsedTime, 360.0f);

    if(currentState == State::Game){
        if(currentLevel < this->levels.size()){
            this->levels[currentLevel]->controls(this->pressed, elapsedTime, &currentLevel);

            if(currentLevel < this->levels.size()){
                this->levels[currentLevel]->collision();
            }
        } else {
            // Quand tous les niveaux sont faits
            currentState = State::WellDone;
            mousePressed = false;
        }
    }
    
    Render();
}

void App::Render() {
    // Couleur du fond sans rien (ici gris)
    glClearColor((36.f/255.f), (36.f/255.f),(36.f/255.f), 1.f);

    glClear(GL_COLOR_BUFFER_BIT);
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);

    //Exemple d'un niveau
        if(currentState == State::Game){
            if(currentLevel < this->levels.size()){
                // Permet d'afficher le jeu sans problème (s'assure qu'il n'y ait plus de texture)
                glDisable(GL_TEXTURE_2D);
                glLoadIdentity();

                // TODO cube with level number

                glPushMatrix();
                glTranslatef(this->levels[currentLevel]->camera.x, this->levels[currentLevel]->camera.y, 0);
                this->levels[currentLevel]->drawMap();
                this->levels[currentLevel]->drawPlayers();
                glPopMatrix();
            } else {
                currentState = State::WellDone;
                this->mousePressed = false;
                initLevel(&level1, playersLvl1, mLvl1, 0.1f, finalPosition);
                this->levels = {&level1};
                currentLevel = 0;
            }
        }

    // Homepage
    if(currentState == State::Homepage){
        // printf("Homepage");
        glLoadIdentity();
        currentState = displayHomepage(_textureId, cursorPosition, mousePressed);
        this->mousePressed = false;
    }

    // Rules
    if(currentState == State::Rules){
        // printf("Rules");
        currentState = displayRulespage(_textureId, cursorPosition, mousePressed, translateY);
        scroll = 0;
        this->mousePressed = false;
    }

    // GameOver
    if(currentState == State::GameOver){
        currentState = displayGameOver(_textureId, cursorPosition,mousePressed);
        this->mousePressed = false;
    }

     // WellDone
    if(currentState == State::WellDone){
        currentState = displayWellDone(_textureId, cursorPosition,mousePressed);
        this->mousePressed = false;
    }

    // WellDone
    if(currentState == State::Credits){
        // printf("Credits");
        currentState = displayCredits(_textureId, cursorPosition,mousePressed);
        this->mousePressed = false;
    }
}

void App::key_callback(int key, int scancode, int action, int mods) {
    // std::cout << key << " was " << action << std::endl;

    if(action == GLFW_PRESS)
        this->pressed[key] = true;
    else if(action == GLFW_RELEASE)
        this->pressed[key] = false;

    if(currentLevel < this->levels.size()){
    // function qui permet d'envoyer les keycode au niveau
        this->levels[currentLevel]->key_callback(key, scancode, action, mods);
    }
}

void App::mouse_button_callback(int button, int action, int mods) {
    
    // mes manips clics
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
            this->mousePressed = true;
        } 

        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE){
            this->mousePressed = false;
        } 
    
}

void App::scroll_callback(double xoffset, double yoffset) {
    // printf("scroll : %f \n", yoffset);

    this->scroll = (int) yoffset;

    if(scroll == 1){
        translateY += 20;
    }
    if(scroll == -1){
        translateY -= 20;
    }
}

void App::cursor_position_callback(double xpos, double ypos) {
    //gestion hover
    
    this->cursorPosition.x = (float) xpos;
    this->cursorPosition.y = (float) ypos;
}

void App::size_callback(int width, int height) {
    _width  = width;
    _height = height;

    // make sure the viewport matches the new window dimensions
    glViewport(0, 0, _width, _height);

    const float aspectRatio = _width / (float) _height;

    // Change the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if( aspectRatio > 1) {
        glOrtho(-_viewSize / 2.0f * aspectRatio, _viewSize / 2.0f * aspectRatio, -_viewSize / 2.0f, _viewSize / 2.0f, -1.0f, 1.0f);
    } else {
        glOrtho(-_viewSize / 2.0f, _viewSize / 2.0f, -_viewSize / 2.0f / aspectRatio, _viewSize / 2.0f / aspectRatio, -1.0f, 1.0f);
    }
}

glm::vec2 App::rotateVec2(const glm::vec2& vec, const glm::vec2& center, const float& angle) {
    return glm::rotate(vec-center,  glm::radians(angle))+center;
}
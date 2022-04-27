#pragma once
#ifndef CAMERA_H
#define CAMERA_H
#include <glm/glm.hpp>
#include "Formes.hpp"

class Camera
{
private:
    glm::vec2 position;
public:
    // Constructeur
    Camera();

    // Permet le suivi d'un perso
    void move(Rectangle playerFocus);
};

#endif
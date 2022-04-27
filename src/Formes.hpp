#pragma once
#ifndef FORMES_H
#define FORMES_H
#include <glm/glm.hpp>

class Rectangle
{
private:
    glm::vec3 color;
    glm::vec2 position;
    float weight = 0;
    float halfHeight;
    float halfWidth;
    enum power;
public:
    // Constructeur
    Rectangle(float hW, float hH, glm::vec3 c, glm::vec2 p);
    
    // Constructeur avec poids
    Rectangle(float hW, float hH, glm::vec3 c, glm::vec2 p, float w);

    // Tracé de la forme
    void draw();

    // Permet de calculer les collisions avec les autres persos et le décor
    void collision();

    // Permet de tourner le rectangle de 90°
    void rotation();

    // Permet de déplacer le personnage
    void move(int direction); 

    // Accès à la position
    glm::vec2 getPosition();

    // Accès aux dimensions
    glm::vec2 getSize();
};

class Triangle
{
private:
    glm::vec3 color;
    glm::vec2 position;
    float rayon;
public:
    // Constructeur
    Triangle(float r, glm::vec3 c, glm::vec2 p);

    // Tracé de la forme
    void draw();
};
#endif
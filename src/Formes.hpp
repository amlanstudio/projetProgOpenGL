#pragma once
#ifndef FORMES_H
#define FORMES_H
#include <glm/glm.hpp>
#include <vector>

class Rectangle
{
private:
    glm::vec3 color;
    glm::vec2 position;
    float weight = 0;
    float halfHeight;
    float halfWidth;

    // TODO pouvoir à gérer
    // enum power;

    bool isJumping = false;
public:
    // Constructeur
    Rectangle(float hW, float hH, glm::vec3 c, glm::vec2 p);
    
    // Constructeur avec poids
    Rectangle(float hW, float hH, glm::vec3 c, glm::vec2 p, float w);

    // Tracé de la forme
    void draw();

    // Permet de calculer les collisions avec les autres persos et le décor
    void collision(Rectangle * other);

    // Permet de tourner le rectangle de 90°
    void rotation();

    // Permet de déplacer le personnage
    void move(int direction); 

    // Permet de dire si le personnage saute ou pas
    void setJump(bool jumping);

    // Accès à la position
    glm::vec2 getPosition();

    // Set d'une nouvelle position
    void setPosition(glm::vec2 p);

    // Accès à la couleur
    glm::vec3 getColor();

    // Set d'une couleur
    void setColor(glm::vec3 c);

    // Accès aux dimensions
    glm::vec2 getSize();

    // Accès au poids
    float getWeight();

    // Permet de gérer collision
    // TODO Quad Tree à faire
    // TODO surement collisions pas parfaites
    // glm::vec2 collisionLateral(std::vector<Rectangle> others);
    // glm::vec2 collisionVertical(std::vector<Rectangle> others);
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
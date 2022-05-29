#pragma once
#ifndef FORMES_H
#define FORMES_H
#include <glm/glm.hpp>
#include <vector>

enum class Power{
    Rotate,
    Nothing
};

class Rectangle
{
private:
    
    glm::vec2 position;
    glm::vec2 oldPosition;

    float weight = 0;
    float halfHeight;
    float halfWidth;

    // Destroy à implémenter un jour
    Power power;

    bool isJumping = false;
public:
    float velocity = 0;
    // Constructeur avec poids optionnel
    Rectangle(float hW, float hH, glm::vec3 c, glm::vec2 p, float w = 0.0f, Power pow = Power::Nothing);
    
    // Tracé de la forme
    void draw();

    // Permet de calculer les collisions avec les autres persos et le décor
    void collision(Rectangle * other);

    // Permet de voir si il contient un autre élément
    bool contains(Rectangle * element);

    // Permet de tourner le rectangle de 90°
    void rotation();

    // Permet la destruction d'une forme de meme couleur à implémenter
    void destroy();

    // Fonction de saut
    void jump();

    // Permet de déplacer le personnage
    void move(bool *  pressed, double time); 

    // Application de la gravité
    void applyGravity(float gravity, double time);

    // Permet de dire si le personnage saute ou pas
    void setJump(bool jumping);

    // Accès à la position
    glm::vec2 getPosition();

    // Set d'une nouvelle position
    void setPosition(glm::vec2 p);

    void savePosition();

    // Accès à la couleur
    glm::vec3 getColor();

    // Set d'une couleur
    void setColor(glm::vec3 c);

    // Accès aux dimensions
    glm::vec2 getSize();

    // Accès au poids
    float getWeight();

    glm::vec3 color;
    
    float top();
    float bottom();
    float left();
    float right();

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
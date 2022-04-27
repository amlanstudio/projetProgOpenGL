#include "Formes.hpp"
#include "glad/glad.h"
#include <math.h>

float vitesse = 50;

Rectangle::Rectangle(float hW, float hH, glm::vec3 c, glm::vec2 p){
    this->halfHeight = hH;
    this->halfWidth = hW;
    this->color = c;
    this->position = p;
}

Rectangle::Rectangle(float hW, float hH, glm::vec3 c, glm::vec2 p, float w){
    this->halfHeight = hH;
    this->halfWidth = hW;
    this->color = c;
    this->position = p;
    this->weight = w;
}

void Rectangle::draw(){
    glColor3f(this->color.r, this->color.g, this->color.b);
    glBegin(GL_QUADS);
        glVertex2f(this->position.x-this->halfWidth, this->position.y-this->halfHeight);
        glVertex2f(this->position.x+this->halfWidth, this->position.y-this->halfHeight);
        glVertex2f(this->position.x+this->halfWidth, this->position.y+this->halfHeight);
        glVertex2f(this->position.x-this->halfWidth, this->position.y+this->halfHeight);
    glEnd();
}

void Rectangle::move(int direction){
    switch (direction)
    {
    case -1:
        this->position.x -= 50/weight;
        break;
        
    case 1:
        this->position.x += 50/weight;
        break;
    
    default:
        break;
    }
} 

glm::vec2 Rectangle::getPosition(){
    return this->position;
}

glm::vec2 Rectangle::getSize(){
    glm::vec2 s(this->halfWidth, this->halfHeight);
    return s;
}

Triangle::Triangle(float r, glm::vec3 c, glm::vec2 p){
    this->rayon = r;
    this->color = c;
    this->position = p;
}

void Triangle::draw(){
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(this->color.r, this->color.g, this->color.b);
        glVertex2f(this->position.x, this->position.y);

        for(int i = 0; i <= 3; i++) 
        {
            // TODO la variable M_PI ne fonctionne pas même avec l'include math.h, pourquoi ?
            float x = this->position.x + this->rayon * cos(i * (2 * 3.14 / (float) 3)-0.55);
            float y = this->position.y + this->rayon * sin(i * (2 * 3.14 / (float) 3)-0.55);
            glVertex2f(x, y);
        }
    glEnd();
}
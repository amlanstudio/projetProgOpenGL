#include "Formes.hpp"
#include "glad/glad.h"
#include <math.h>

float vitesse = 100;

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

void Rectangle::setPosition(glm::vec2 p){
    this->position = p;
}

glm::vec2 Rectangle::getSize(){
    glm::vec2 s(this->halfWidth, this->halfHeight);
    return s;
}

float Rectangle::getWeight(){
    return this->weight;
}

// bool Rectangle::collision(std::vector<Rectangle> others, int gravity){
//     bool boolean = false;
//     int sideCollision = 0;
//     for (int i = 0; i < others.size(); i++)
//     {
//         if(this->position.y+this->halfHeight >= others[i].position.y-others[i].halfHeight){
//             // Collision en bas
//             boolean = true;
//         }
//     }

//     if(!boolean){
//         this->position.y +=gravity*this->weight/10;
//     }

//     return boolean;
// }

glm::vec2 Rectangle::collisionLateral(std::vector<Rectangle> others){
    for (int i = 0; i < others.size(); i++)
    {
        std::vector<Rectangle> col = {others[i]};
        if((this->position.x - this->halfWidth <= others[i].position.x + others[i].halfWidth &&
        this->position.x + this->halfWidth >= others[i].position.x - others[i].halfWidth &&
        this->position.y - this->halfHeight <= others[i].position.y + others[i].halfHeight &&
        this->position.y + this->halfHeight >= others[i].position.y - others[i].halfHeight))
        {
            //si le character vient vers la gauche
            if(this->position.x - this->halfWidth < others[i].position.x + others[i].halfWidth-10)
            {
                glm::vec2 retour(-1, i);
                return retour;
            }
            //s'il est a droite 
            else if(this->position.x + this->halfWidth > others[i].position.x - others[i].halfWidth)
            {
                glm::vec2 retour(1, i);
                return retour;
            } 
        }
    }
    glm::vec2 retour(0, 0);
    return retour;
}

glm::vec2 Rectangle::collisionVertical(std::vector<Rectangle> others){
    for (int i = 0; i < others.size(); i++)
    {
        if((this->position.x - this->halfWidth <= others[i].position.x + others[i].halfWidth &&
        this->position.x + this->halfWidth >= others[i].position.x - others[i].halfWidth &&
        this->position.y - this->halfHeight <= others[i].position.y + others[i].halfHeight &&
        this->position.y + this->halfHeight >= others[i].position.y - others[i].halfHeight))
        {
            if(this->position.y+this->halfHeight >= others[i].position.y - others[i].halfHeight - 10){
                glm::vec2 retour(1, i);
                return retour;
            } else {
                glm::vec2 retour(0, 0);
                return retour;
            }
        }
    }
    glm::vec2 retour(0, 0);
    return retour;
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
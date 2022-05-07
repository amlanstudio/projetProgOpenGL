#include "Formes.hpp"
#include "glad/glad.h"

#include <glm/gtc/constants.hpp>

#include <iostream>

float vitesse = 0.05f;
float jump = 0.1f;

Rectangle::Rectangle(float hW, float hH, glm::vec3 c, glm::vec2 p){
    this->halfHeight = hH;
    this->halfWidth = hW;
    this->color = c;
    this->position = p;
    this->oldPosition = p;
}

Rectangle::Rectangle(float hW, float hH, glm::vec3 c, glm::vec2 p, float w){
    this->halfHeight = hH;
    this->halfWidth = hW;
    this->color = c;
    this->position = p;
    this->oldPosition = p;
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

void Rectangle::collision(Rectangle* other){
    if(
        this->position.y - this->halfHeight > other->position.y + other->halfHeight ||
        this->position.y + this->halfHeight < other->position.y - other->halfHeight ||
        this->position.x - this->halfWidth > other->position.x + other->halfWidth ||
        this->position.x + this->halfWidth < other->position.x - other->halfWidth
    ) {
        return;
    }

    if(
        this->position.y - this->halfHeight < other->position.y + other->halfHeight && this->oldPosition.y - this->halfHeight >= other->oldPosition.y + other->halfHeight
    ){
        this->isJumping = false;

        this->position.y = other->position.y + other->halfHeight + this->halfHeight;
    } else if(
        this->position.y + this->halfHeight > other->position.y - other->halfHeight && this->oldPosition.y + this->halfHeight <= other->oldPosition.y - other->halfHeight
    ) {
        this->position.y = other->position.y - other->halfHeight - this->halfHeight;
    }else if(
        this->position.x - this->halfWidth < other->position.x + other->halfWidth && this->oldPosition.x - this->halfWidth >= other->oldPosition.x + other->halfWidth
    ) {
        this->position.x = other->position.x + other->halfWidth + this->halfWidth;
    }else if(
        this->position.x + this->halfWidth > other->position.x - other->halfWidth && this->oldPosition.x + this->halfWidth <= other->oldPosition.x - other->halfWidth 
    ) {
        this->position.x = other->position.x - other->halfWidth - this->halfWidth;
    }

    // if(
    //     this->position.y - this->halfHeight < other->position.y + other->halfHeight && this->oldPosition.y > this->position.y
    // ){
    //     this->isJumping = false;

    //     this->position.y = other->position.y + other->halfHeight + this->halfHeight+0.0001f;
    // } else if(
    //     this->position.y + this->halfHeight > other->position.y - other->halfHeight && this->oldPosition.y < this->position.y
    // ) {
    //     this->position.y = other->position.y - other->halfHeight - this->halfHeight-0.0001f;
    // }else if(
    //     this->position.x - this->halfWidth < other->position.x + other->halfWidth && this->oldPosition.x > this->position.x
    // ) {
    //     this->position.x = other->position.x + other->halfWidth + this->halfWidth+0.0001f;
    // }else if(
    //     this->position.x + this->halfWidth > other->position.x - other->halfWidth && this->oldPosition.x < this->position.x 
    // ) {
    //     this->position.x = other->position.x - other->halfWidth - this->halfWidth-0.0001f;
    // }

}

void Rectangle::move(int direction){

    switch (direction)
    {
    case -1:
        this->position.x -= vitesse/weight;
        break;
        
    case 1:
        this->position.x += vitesse/weight;
        break;

    case 2:
        if(!this->isJumping) this->position.y += jump/this->weight;
        break;

    case 3:
        this->position.x += vitesse/weight;
        if(!this->isJumping) this->position.y += jump/this->weight;
        break;

    case -3:
        this->position.x -= vitesse/weight;
        if(!this->isJumping) this->position.y += jump/this->weight;
        break;
    
    default:
        break;
    }
}

void Rectangle::applyGravity(float gravity){
    this->position.y = this->position.y - gravity * this->getWeight()/50;
}

void Rectangle::setJump(bool jumping){
    this->isJumping = jumping;
}

glm::vec2 Rectangle::getPosition(){
    return this->position;
}

void Rectangle::setPosition(glm::vec2 p){
    this->position = p;
}

glm::vec3 Rectangle::getColor(){
    return this->color;
}

void Rectangle::setColor(glm::vec3 c){
    this->color = c;
}

glm::vec2 Rectangle::getSize(){
    glm::vec2 s(this->halfWidth, this->halfHeight);
    return s;
}

float Rectangle::getWeight(){
    return this->weight;
}

/*

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
                glm::vec2 retour(0, -1);
                return retour;
            }
        }
    }
    glm::vec2 retour(0, 0);
    return retour;
}

*/

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
            float x = this->position.x + this->rayon * cos(i * (2.0f * glm::pi<float>() / 3.f)+0.5f);
            float y = this->position.y + this->rayon * sin(i * (2.0f * glm::pi<float>() / 3.f)+0.5f);
            glVertex2f(x, y);
        }
    glEnd();
}
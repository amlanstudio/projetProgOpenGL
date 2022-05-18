#include "Formes.hpp"
#include "glad/glad.h"

#include <glm/gtc/constants.hpp>
#include "GLFW/glfw3.h"

#include <iostream>

float vitesse = 0.05f;
float jump = 0.01f;
int jumpTimer = 0;

Rectangle::Rectangle(float hW, float hH, glm::vec3 c, glm::vec2 p, float w, Power pow){
    this->halfHeight = hH;
    this->halfWidth = hW;
    this->color = c;
    this->position = p;
    this->oldPosition = p;
    this->weight = w;
    power = pow;
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
}

bool Rectangle::contains(Rectangle * element){
    //si l'angle up L de element est dans le rectangle
    // ou si l'angle up R de element est dans le rectangle
    // ou si l'angle bottom L de element est dans le rectangle
    // ou si l'angle bottom R de element est dans le rectangle

    // return (element->position.x - element->halfWidth > position.x - halfWidth && element->position.x - element->halfWidth < position.x + halfWidth && element->position.y + element->halfHeight > position.y + halfHeight && element->position.y + element->halfHeight < position.y - halfHeight);

    // printf("e %f %f %f %f\n", element->top(), element->bottom(), element->left(), element->right());
    // printf("this %f %f %f %f\n", top(), bottom(), left(), right());

    return (
    element->position.x - element->halfWidth > position.x - halfWidth && element->position.x - element->halfWidth < position.x + halfWidth && 
    element->position.y + element->halfHeight > position.y - halfHeight && element->position.y + element->halfHeight < position.y + halfHeight

    ||

    element->position.x + element->halfWidth > position.x - halfWidth && element->position.x + element->halfWidth < position.x + halfWidth && 
    element->position.y + element->halfHeight > position.y - halfHeight && element->position.y + element->halfHeight < position.y + halfHeight

    ||

    element->position.x - element->halfWidth > position.x - halfWidth && element->position.x - element->halfWidth < position.x + halfWidth && 
    element->position.y - element->halfHeight > position.y - halfHeight && element->position.y - element->halfHeight < position.y + halfHeight

    ||

    element->position.x + element->halfWidth > position.x - halfWidth && element->position.x + element->halfWidth < position.x + halfWidth && 
    element->position.y - element->halfHeight > position.y - halfHeight && element->position.y - element->halfHeight < position.y + halfHeight
    );
}

void Rectangle::rotation(){
    if(power == Power::Rotate){
        float tempWidth = halfWidth;
        halfWidth = halfHeight;
        halfHeight = tempWidth;

        position.y += halfHeight;
    }
};

void Rectangle::jump(){
    velocity = 1.f;
}

void Rectangle::move(bool * pressed, double time){

    if(pressed[GLFW_KEY_UP] && !this->isJumping){
        this->jump();
        isJumping = true;
    }

    if(pressed[GLFW_KEY_LEFT]) this->position.x -= vitesse/weight;
    if(pressed[GLFW_KEY_RIGHT]) this->position.x += vitesse/weight;
}

void Rectangle::applyGravity(float gravity, double time){
    velocity -= gravity * this->getWeight()/50;
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

void Rectangle::savePosition(){
    oldPosition = position;
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
            float x = this->position.x + this->rayon * cos(i * (2.0f * glm::pi<float>() / 3.f)+0.5f);
            float y = this->position.y + this->rayon * sin(i * (2.0f * glm::pi<float>() / 3.f)+0.5f);
            glVertex2f(x, y);
        }
    glEnd();
}

    float Rectangle::top()
    {
        return position.y + halfHeight;
    }

    float Rectangle::bottom()
    {
        return position.y - halfHeight;
    }
 
    float Rectangle::left()
    {
        return position.x - halfWidth;
    }

    float Rectangle::right()
    {
        return position.x + halfWidth;
    }
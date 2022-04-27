#pragma once
#ifndef VARIABLES_H
#define VARIABLES_H
#include <glm/glm.hpp>
#include "Formes.hpp"
#include "Window.hpp"

const glm::vec2 halfSize(WIDTH/2.f, HEIGHT/2.f);

// Exemple d'un rectangle
    // ici sa couleur normalisée entre 0 et 1
    glm::vec3 c(1, 1, 1);

    // ici sa position
    glm::vec2 p(halfSize.x, halfSize.y);

    // ici son poids
    float w = 25;

    // ici on construit le rectangle
    Rectangle test(WIDTH/15, HEIGHT/15, c, p, w);

    glm::vec2 pos(halfSize.x-500, halfSize.y);
    Rectangle p2(WIDTH/15, HEIGHT/5, c, pos, w);

//Exemple d'un niveau
    // ici on crée le vector de personnages du niveau 1
    std::vector<Rectangle> pLvl1 = {test, p2};

    // ici on construit le niveau avec ses personnages
    Niveau niv1(pLvl1);
#endif
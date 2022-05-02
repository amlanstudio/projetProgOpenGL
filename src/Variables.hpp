#pragma once
#ifndef VARIABLES_H
#define VARIABLES_H
#include <glm/glm.hpp>
#include "Formes.hpp"
#include "Window.hpp"

// Exemple d'un rectangle
    // ici sa couleur normalisée entre 0 et 1
    glm::vec3 c(1, 1, 1);

    // ici sa position
    glm::vec2 p(halfSize.x, halfSize.y);

    // ici son poids
    float w = 5;

    // ici on construit le rectangle
    Rectangle test(WIDTH/15, HEIGHT/15, c, p, w);

    glm::vec3 g(0, 1, 0);

    glm::vec2 pos(halfSize.x-500, halfSize.y);
    Rectangle p2(WIDTH/15, HEIGHT/5, g, pos, w);


// Création d'un sol
    glm::vec3 blue(0, 0, 1);
    glm::vec2 pSol(halfSize.x, HEIGHT);
    Rectangle sol(WIDTH, HEIGHT/10, blue, pSol, 0);

//Exemple d'un niveau
    // ici on crée le vector de personnages du niveau 1
    std::vector<Rectangle> pLvl1 = {test, p2};

    // ici on crée le vector de formes du décor du niveau 1
    std::vector<Rectangle> mLvl1 = {sol};

    // // ici on construit le niveau avec ses personnages et son décor et sa gravité
    // Niveau niv1(pLvl1, mLvl1, 10);
    
    // ici on construit le niveau avec ses personnages et son décor sa gravité et sa camera
    Niveau niv1(pLvl1, mLvl1, 10);
#endif
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
    glm::vec2 p(0, 0);

    // ici son poids
    float w = 5;

    // ici on construit le rectangle
    Rectangle test(0.1, 0.1, c, p, w);

    glm::vec3 g(0, 1, 0);

    glm::vec2 pos(-0.5, 0);
    Rectangle p2(0.1, 0.2, g, pos, w);


// Création d'un sol
    glm::vec3 blue(0, 0, 1);
    glm::vec2 pSol(0, -HEIGHT);
    Rectangle sol(WIDTH, HEIGHT/5, blue, pSol, 0);

//Exemple d'un niveau
    // ici on crée le vector de personnages du niveau 1
    std::vector<Rectangle> pLvl1 = {test, p2};

    // ici on crée le vector de formes du décor du niveau 1
    std::vector<Rectangle> mLvlT = {sol};

    // // ici on construit le niveau avec ses personnages et son décor et sa gravité
    // Niveau niv1(pLvl1, mLvl1, 10);
    
    // ici on construit le niveau avec ses personnages et son décor sa gravité et sa camera
    Niveau niv1(pLvl1, mLvlT, 0.1);

// Test Level 1 définitif
    // Map
    glm::vec3 noir(0, 0, 0);
    glm::vec3 jaune(1, 1, 0);
    glm::vec3 jauneBlur(0.5, 0.5, 0);
    glm::vec3 rouge(1, 0, 0);
    glm::vec3 rougeBlur(0.5, 0, 0);

    glm::vec2 pSol1(WIDTH, -HEIGHT);
    Rectangle solLvl1(WIDTH*2, HEIGHT/5, noir, pSol1);

    glm::vec2 pPlafond1(WIDTH, HEIGHT);
    Rectangle plafondLvl1(WIDTH*2, HEIGHT/5, noir, pPlafond1);

    glm::vec2 pMurG(-WIDTH*1.5, 0);
    Rectangle murGLvl1(WIDTH*0.5, HEIGHT*1.5, noir, pMurG);
    
    glm::vec2 pMurD(WIDTH*3.5, 0);
    Rectangle murDLvl1(WIDTH*0.5, HEIGHT*1.5, noir, pMurD);

    glm::vec2 pObs1(WIDTH/2, -HEIGHT+0.3);
    Rectangle obsLvl1(0.1, 0.11, noir, pObs1);

    glm::vec2 pObs2(WIDTH + (WIDTH/2), -HEIGHT+0.3);
    Rectangle obs2Lvl1(0.1, 0.11, noir, pObs2);

    std::vector<Rectangle> mLvl1 ={solLvl1, plafondLvl1, murGLvl1, murDLvl1, obsLvl1, obs2Lvl1};

    // Players
    // TODO à ajuster
    Rectangle playerLvl1(0.1, 0.1, jaune, p, w);
    Rectangle player2Lvl1(0.1, 0.2, rouge, pos, w);

    std::vector<Rectangle> playersLvl1 = {playerLvl1, player2Lvl1};

    // Final Position Players
    glm::vec2 pEnd(WIDTH + (3*WIDTH/4), -HEIGHT+0.3);
    Rectangle endPlayerLvl1(0.1, 0.1, jauneBlur, pEnd);

    glm::vec2 posEnd(WIDTH + (3*WIDTH/4) + 0.25, -HEIGHT+0.4);
    Rectangle endPlayer2Lvl1(0.1, 0.2, rougeBlur, posEnd);

    std::vector<Rectangle> finalPosition = {endPlayerLvl1, endPlayer2Lvl1};

    // Level
    Niveau lvl1(playersLvl1, mLvl1, 0.1, finalPosition);

#endif
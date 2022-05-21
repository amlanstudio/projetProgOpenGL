#pragma once
#ifndef VARIABLES_H
#define VARIABLES_H
#include <glm/glm.hpp>
#include "Formes.hpp"
#include "Niveau.hpp"
#include "Window.hpp"

    // ici sa position
    glm::vec2 p(0, 0);

    // ici son poids
    float w = 5.0f;

    glm::vec2 pos(-0.5, 0);

// Test Level 1 définitif
    // Map
    glm::vec3 noir(0, 0, 0);
    glm::vec3 jaune(1, 1, 0);
    glm::vec3 jauneBlur(0.5, 0.5, 0);
    glm::vec3 rouge(1, 0, 0);
    glm::vec3 rougeBlur(0.5, 0, 0);

    glm::vec2 pSol1(WIDTH, -HEIGHT);
    Rectangle solLvl1(WIDTH*1.8f, HEIGHT/5, noir, pSol1);

    glm::vec2 pPlafond1(WIDTH, HEIGHT);
    Rectangle plafondLvl1(WIDTH*1.8f, HEIGHT/5, noir, pPlafond1);

    glm::vec2 pMurG(-WIDTH*1.2, 0);
    Rectangle murGLvl1(WIDTH*0.5f, HEIGHT*1.5f, noir, pMurG);
    
    glm::vec2 pMurD(WIDTH*3.2, 0);
    Rectangle murDLvl1(WIDTH*0.5f, HEIGHT*1.5f, noir, pMurD);

    glm::vec2 pObs1(WIDTH/2.f, -HEIGHT+0.3f);
    Rectangle obsLvl1(0.1f, 0.11f, noir, pObs1);

    glm::vec2 pObs2(WIDTH + (WIDTH/2), -HEIGHT+0.3);
    Rectangle obs2Lvl1(0.1f, 0.11f, noir, pObs2);

    std::vector<Rectangle> mLvl1 ={solLvl1, plafondLvl1, murGLvl1, murDLvl1, obsLvl1, obs2Lvl1};

    // Players
    // TODO à ajuster
    Rectangle playerLvl1(0.1f, 0.1f, jaune, p, w);
    Rectangle player2Lvl1(0.1f, 0.2f, rouge, pos, w, Power::Rotate);

    std::vector<Rectangle> playersLvl1 = {playerLvl1, player2Lvl1};

    // Final Position Players
    glm::vec2 pEnd(WIDTH + (3*WIDTH/4), -HEIGHT+0.3);
    Rectangle endPlayerLvl1(0.1f, 0.1f, jauneBlur, pEnd);

    glm::vec2 posEnd((WIDTH + (3*WIDTH/4) + 0.25), (-HEIGHT+0.4));
    Rectangle endPlayer2Lvl1(0.1f, 0.2f, rougeBlur, posEnd);

    std::vector<Rectangle> finalPosition = {endPlayerLvl1, endPlayer2Lvl1};

// Levels    
    Niveau level1;
#endif
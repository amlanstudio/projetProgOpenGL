#pragma once
#ifndef VARIABLES_H
#define VARIABLES_H
#include <glm/glm.hpp>
#include "Formes.hpp"
#include "Niveau.hpp"
#include "Window.hpp"

    // Couleurs initialisation globale
        glm::vec3 noir(0.f,0.f,0.f);
        glm::vec3 jaune(1.f, (210.f/255.f), (27.f/255.f)); 
        glm::vec3 jauneBlur(0.5f, (105.f/255.f), (13.5f/255.f));
        glm::vec3 rouge(1, 0, 0);
        // glm::vec3 rougeBlur(0.5, 0, 0);
        glm::vec3 bleu((77.f/255.f),(155.f/255.f), (208.f/255.f));
        glm::vec3 bleuBlur((38.5f/255.f),(77.5f/255.f), (104.f/255.f));
        glm::vec3 rose((231.f/255.f),(76.f/255.f), (127.f/255.f));
        glm::vec3 roseBlur((115.5f/255.f),(38.f/255.f), (63.5f/255.f));
    
    // Poids global
        float w = 5.0f;
    //Poids rectangle rose 
        float wRose=4.f; //ne pas descendre en dessous de 4. 

    // Position
    glm::vec2 p(0, 0);
    glm::vec2 pos(-0.5, 0);
    
// Levels 
// Niveau 1   
    Niveau level1;

    // Players
    Rectangle playerLvl1(0.1f, 0.1f, jaune, p, w);
    Rectangle player2Lvl1(0.1f, 0.2f, rose, pos, wRose, Power::Rotate);

    std::vector<Rectangle> playersLvl1 = {playerLvl1, player2Lvl1};

    // Map
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

    // Final Position Players
    glm::vec2 pEnd(WIDTH + (3*WIDTH/4), -HEIGHT+0.3);
    Rectangle endPlayerLvl1(0.1f, 0.1f, jauneBlur, pEnd);

    glm::vec2 posEnd((WIDTH + (3*WIDTH/4) + 0.25), (-HEIGHT+0.4));
    Rectangle endPlayer2Lvl1(0.1f, 0.2f, roseBlur, posEnd);

    std::vector<Rectangle> finalPosition = {endPlayerLvl1, endPlayer2Lvl1};
    

// LEVEL 2

    Niveau level2;

    // Poids carrés Level2

        float wCarreLvl2 = 6.0f;

    // Position Depart Players Level 2

    // ici sa position depart
    glm::vec2 p1L2(0.f, 0.2f);
    glm::vec2 p2L2(-0.5f, 0.2f);
    glm::vec2 p3L2(-1.f, 0.2f);

    // Players level 2

    Rectangle playerLvl2(0.1f, 0.1f, jaune, p1L2, wCarreLvl2); //carré jaune basic
    Rectangle player2Lvl2(0.1f, 0.1f, bleu, p2L2, wCarreLvl2); //carré bleu destructeur //TODO pouvoir de destruction
    Rectangle player3Lvl2(0.1f, 0.2f, rose, p3L2, wRose, Power::Rotate); //carré rose rotatif

    std::vector<Rectangle> playersLvl2 = {playerLvl2, player2Lvl2, player3Lvl2};

    // Position finale Players level 2

    glm::vec2 p1L2End(WIDTH + (3*WIDTH/4), -HEIGHT+0.7); //0.3 pour les carrés (height)
    Rectangle endPlayerLvl2(0.1f, 0.1f, jauneBlur, p1L2End);

    glm::vec2 p2L2End((WIDTH + (3*WIDTH/4) + 0.25), (-HEIGHT+0.7));
    Rectangle endPlayer2Lvl2(0.1f, 0.1f, bleuBlur, p2L2End);

    glm::vec2 p3L2End((WIDTH + (3*WIDTH/4) + 0.50), (-HEIGHT+0.8)); //0.4 pour rectangles
    Rectangle endPlayer3Lvl2(0.1f, 0.2f, roseBlur, p3L2End);

    std::vector<Rectangle> finalPositionLvl2 = {endPlayerLvl2, endPlayer2Lvl2,endPlayer3Lvl2};

    // MAP Level 2

    // Map same as level 1
    
    glm::vec2 pSol2(WIDTH, -HEIGHT);
    Rectangle solLvl2(WIDTH*1.8f, HEIGHT/5, noir, pSol1);

    glm::vec2 pPlafond2(WIDTH, HEIGHT);
    Rectangle plafondLvl2(WIDTH*1.8f, HEIGHT/5, noir, pPlafond1);

    glm::vec2 pMurG2(-WIDTH*1.2f, 0.f);
    Rectangle murGLvl2(WIDTH*0.5f, HEIGHT*1.5f, noir, pMurG);
    
    glm::vec2 pMurD2(WIDTH*3.2f, 0.f);
    Rectangle murDLvl2(WIDTH*0.5f, HEIGHT*1.5f, noir, pMurD);

    // Obstacles Level 2

    glm::vec2 pObs1Lvl2(0, -HEIGHT+0.4f);
    Rectangle obsLvl2(WIDTH-0.6f, 0.2f, noir, pObs1Lvl2);

    glm::vec2 pObs2Lvl2(WIDTH + (WIDTH) - 0.35f, -HEIGHT+0.4);
    Rectangle obs2Lvl2(WIDTH, 0.2f, noir, pObs2Lvl2); 

    glm::vec2 pObs3Lvl2(0.8f, -HEIGHT+0.7f);
    Rectangle obs3Lvl2(0.1f, 0.1f, noir, pObs3Lvl2);

    glm::vec2 pObs4Lvl2(WIDTH + (WIDTH) - 1.5f, -HEIGHT+1.0f); // on ne touche plus à lui
    Rectangle obs4Lvl2(0.2f, 0.4f, noir, pObs4Lvl2);

    glm::vec2 pObs5Lvl2(WIDTH + (WIDTH) - 1.9f, -HEIGHT+0.7f);
    Rectangle obs5Lvl2(0.3f, 0.05f, noir, pObs5Lvl2);
    
    glm::vec2 pObs6Lvl2(WIDTH + (WIDTH) - 1.7f, -HEIGHT+1.1f);
    Rectangle obs6Lvl2(0.2f, 0.08f, noir, pObs6Lvl2);

    std::vector<Rectangle> mapLvl2 = {solLvl2, plafondLvl2, murGLvl2, murDLvl2, obsLvl2, obs2Lvl2,obs3Lvl2, obs4Lvl2,obs5Lvl2,obs6Lvl2};


    // LEVEL 3 Tres similaire à LEVEL 2 (Sarah)

#endif
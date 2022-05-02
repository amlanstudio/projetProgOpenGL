#pragma once
#ifndef NIVEAU_H
#define NIVEAU_H
#include <vector>
#include "Formes.hpp"
#include "Niveau.hpp"
#include <glm/glm.hpp>

class Niveau
{
private:
   std::vector<Rectangle> players;
   std::vector<Rectangle> map;
   float gravity;
   Rectangle* currentPlayer;

public:

    glm::vec2 camera;
    
    // Constructeur
    // Niveau(std::vector<Rectangle> players, std::vector<Rectangle> map, float g);

    // Constructeur avec juste des personnages
    Niveau(std::vector<Rectangle> players);

    // Constructeur avec personnages et décor et gravité
    Niveau(std::vector<Rectangle> players, std::vector<Rectangle> map, float g);

    // Permet de dessiner le décor
    void drawMap();

    // Permet de dessiner les personnages
    void drawPlayers();

    // Permet de changer le personnage actuellement en controle
    void switchPerso();

    // Permet de gérer les players
    void controls(int direction);

    // Permet de gérer les collisions (verticales déjà)
    void collision();
};

#endif
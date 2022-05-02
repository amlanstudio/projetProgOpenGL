#pragma once
#ifndef NIVEAU_H
#define NIVEAU_H
#include <vector>
#include "Formes.hpp"
#include <glm/glm.hpp>

class Niveau
{
private:
   std::vector<Rectangle> players;
   std::vector<Rectangle> map;
   float gravity;
   Rectangle* currentPlayer;

   std::vector<Rectangle> endPlayers;

public:

    // Camera (il s'agit en fait d'un vecteur 2 coordonnees vu qu'on a besoin du x et du y)
    glm::vec2 camera;

    // Constructeur avec juste des personnages
    Niveau(std::vector<Rectangle> players);

    // Constructeur avec personnages et décor et gravité
    Niveau(std::vector<Rectangle> players, std::vector<Rectangle> map, float g);
    
    // Constructeur avec personnages et décor et gravité et positions finales
    Niveau(std::vector<Rectangle> players, std::vector<Rectangle> map, float g, std::vector<Rectangle> end);

    // Permet de dessiner le décor
    void drawMap();

    // Permet de dessiner les personnages
    void drawPlayers();

    // Permet de gérer les players
    void controls(int direction);

    // Permet de gérer les collisions (verticales déjà)
    void collision();
};

#endif
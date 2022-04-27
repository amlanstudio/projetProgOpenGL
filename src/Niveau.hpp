#pragma once
#ifndef NIVEAU_H
#define NIVEAU_H
#include <vector>
// #include "Camera.hpp"
#include "Formes.hpp"

class Niveau
{
private:
//    Camera camera;
   std::vector<Rectangle> players;
   std::vector<Rectangle> map;
   float gravity;
   Rectangle* currentPlayer;
public:
    // Constructeur
    // Niveau(Camera cam, std::vector<Rectangle> players, std::vector<Rectangle> map, float g);

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
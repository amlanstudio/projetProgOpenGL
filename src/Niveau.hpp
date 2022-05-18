#pragma once

#include <vector>
#include "Formes.hpp"
#include "Quadtree.hpp"
#include <glm/glm.hpp>

class Niveau
{
private:
   std::vector<Rectangle> players;
   std::vector<Rectangle> map;
   float gravity;
   Rectangle* currentPlayer;

   std::vector<Rectangle> endPlayers;

   Quadtree* quadtree;

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
    void controls(bool * pressed, double time);

    // Permet de gérer les events
    void key_callback(int key, int scancode, int action, int mods);

    // Permet de gérer les collisions
    void collision();
};

#pragma once

#include "Formes.hpp"
#include <vector>

class Quadtree
{
private:
    Quadtree * upperLeft = nullptr;
    Quadtree * upperRight = nullptr;
    Quadtree * bottomLeft = nullptr;
    Quadtree * bottomRight = nullptr;

    bool isLeaf = true; // est ce que c'est une feuille
    Rectangle* boundary;
    int max = 4;
    std::vector<Rectangle*> collide;
public:
    Quadtree(Rectangle* boundary);

    // Insérer des formes dans le quadtree
    void insert(Rectangle* element);

    // Subdiviser le quadtree
    void subdivide();

    // Récupérer les éléments dans la meme feuille que la position en paramètre
    std::vector<Rectangle *> accessRightLeaf(Rectangle player);

};
#include "Niveau.hpp"
#include "Quadtree.hpp"
#include <iostream>
#include "Window.hpp"
#include "GLFW/glfw3.h"

Niveau::Niveau(std::vector<Rectangle> players){
    this->players = players;
    this->currentPlayer = &(this->players[0]);
}

// Niveau::Niveau(std::vector<Rectangle> players, std::vector<Rectangle> map, float g) {
//     this->players = players;
//     this->currentPlayer = &(this->players[0]);
//     this->map = map;
//     this->gravity = g;
//     this->camera = glm::vec2(0, 0);
// }

Niveau::Niveau(std::vector<Rectangle> players, std::vector<Rectangle> map, float g): 
players(players), 
currentPlayer(&(this->players[0])), 
map(map), 
gravity(g), 
camera(0, 0),
quadtree(new Quadtree(new Rectangle(WIDTH*2, HEIGHT*2, glm::vec3(0,0,0), glm::vec2(WIDTH, 0)))) {}

Niveau::Niveau(std::vector<Rectangle> players, std::vector<Rectangle> map, float g, std::vector<Rectangle> end){
    this->players = players;
    this->currentPlayer = &(this->players[0]);
    this->map = map;
    this->gravity = g;

    glm::vec2 newC(0, 0);
    this->camera = newC;

    this->endPlayers = end;

    this->quadtree = new Quadtree(new Rectangle(WIDTH*2, HEIGHT*2, glm::vec3(0,0,0), glm::vec2(WIDTH, 0)));

    for (size_t i = 0; i < this->map.size(); i++)
    {
        quadtree->insert(&(this->map[i]));
    }
    
}

void Niveau::drawPlayers(){
    for(size_t i = 0; i<this->players.size(); i++){
        this->players[i].draw();
    }

    // Triangle indiquant le current player
        // ici sa couleur normalisée entre 0 et 1
        glm::vec3 c(1, 0, 0);

        // ici sa position
        glm::vec2 p(this->currentPlayer->getPosition());
        p.y += this->currentPlayer->getSize().y + 0.1f;
        Triangle showPlayer(0.05f, c, p);
        showPlayer.draw();
}

void Niveau::drawMap(){
    for(size_t i = 0; i<this->map.size(); i++){
        this->map[i].draw();
    }
    
    for(size_t i = 0; i<this->endPlayers.size(); i++){
        this->endPlayers[i].draw();
    }
}

void Niveau::controls(bool * pressed, double time){

    this->camera.x = - this->currentPlayer->getPosition().x;
    this->camera.y = - this->currentPlayer->getPosition().y - 0.6f;
        
    bool moveable = true;
    for(size_t i=0; i<this->endPlayers.size(); i++){
        if((float)this->currentPlayer->getPosition().x >= (float)this->endPlayers[i].getPosition().x - 0.01 && 
        (float)this->currentPlayer->getPosition().x <= (float)this->endPlayers[i].getPosition().x + 0.01 && 
        (float)this->currentPlayer->getPosition().y >= (float)this->endPlayers[i].getPosition().y - 0.01 &&
        (float)this->currentPlayer->getPosition().y <= (float)this->endPlayers[i].getPosition().y + 0.01
        ){
            moveable = false;

            this->endPlayers[i].setColor(this->currentPlayer->getColor());

            this->map.push_back(this->endPlayers[i]);

            if(this->players.size() != 1){
                this->players.erase(this->players.begin());
                this->currentPlayer = &(this->players[0]);
            } else {
                this->currentPlayer = nullptr;

                // TODO swap level
                printf("Swap level");
            }
        }
    }

    for(size_t i = 0; i<this->players.size(); i++){
        this->players[i].savePosition();
    }

    if(moveable){
        this->currentPlayer->move(pressed, time);
    }

    for(size_t i = 0; i<this->players.size(); i++){
        // TODO souci de gravité sometimes
        this->players[i].applyGravity(this->gravity, time);
        this->players[i].setPosition(glm::vec2(this->players[i].getPosition().x, this->players[i].getPosition().y + this->players[i].velocity * time));
    }
}

void Niveau::key_callback(int key, int scancode, int action, int mods){
    if(key == GLFW_KEY_TAB && action == GLFW_PRESS){
        printf("Changement de joueur\n");
        this->players.push_back(*(this->currentPlayer));
        this->players.erase(this->players.begin());
        this->currentPlayer = &(this->players[0]);
    }

    if(key == GLFW_KEY_R && action == GLFW_PRESS){
        this->currentPlayer->rotation();

        collision();
    }
}

void Niveau::collision(){
    std::vector<Rectangle*> all;

    // // ajout de la map au vector qui servira aux collisions
    // for (size_t m = 0; m < this->map.size() ; m++)
    // {
    //     all.push_back(&(this->map[m]));
    // }

    for(size_t p = 1; p<this->players.size(); p++)
    {

        std::vector<Rectangle*> temp;

        all = this->quadtree->accessRightLeaf(this->players[p]);

        for (size_t a = 0; a < all.size(); a++)
        {
            this->players[p].collision(all[a]);
        }
    }

    all = this->quadtree->accessRightLeaf(*(this->currentPlayer));

    // ajout des players qui ne sont pas courant   
    for (size_t j = 1; j < this->players.size(); j++)
    {
        all.push_back(&(this->players[j]));
    }

    for (size_t a = 0; a < all.size(); a++)
    {
        this->currentPlayer->collision(all[a]);
    }    
}
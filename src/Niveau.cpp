#include "Niveau.hpp"
#include <iostream>
#include "Window.hpp"

Niveau::Niveau(std::vector<Rectangle> players){
    this->players = players;
    this->currentPlayer = &(this->players[0]);
}

Niveau::Niveau(std::vector<Rectangle> players, std::vector<Rectangle> map, float g){
    this->players = players;
    this->currentPlayer = &(this->players[0]);
    this->map = map;
    this->gravity = g;

    glm::vec2 newC(0, 0);
    this->camera = newC;
}

Niveau::Niveau(std::vector<Rectangle> players, std::vector<Rectangle> map, float g, std::vector<Rectangle> end){
    this->players = players;
    this->currentPlayer = &(this->players[0]);
    this->map = map;
    this->gravity = g;

    glm::vec2 newC(0, 0);
    this->camera = newC;

    this->endPlayers = end;
}

void Niveau::drawPlayers(){
    for(int i = 0; i<this->players.size(); i++){
        this->players[i].draw();
    }

    // Triangle indiquant le current player
        // ici sa couleur normalisée entre 0 et 1
        glm::vec3 c(1, 0, 0);

        // ici sa position
        glm::vec2 p(this->currentPlayer->getPosition());
        p.y += this->currentPlayer->getSize().y + 0.1;
        Triangle showPlayer(0.05, c, p);
        showPlayer.draw();
}

void Niveau::drawMap(){
    for(int i = 0; i<this->map.size(); i++){
        this->map[i].draw();
    }
    
    for(int i = 0; i<this->endPlayers.size(); i++){
        this->endPlayers[i].draw();
    }
}

void Niveau::controls(int direction){
    if(direction == 9){
        printf("Changement de joueur");
        this->players.push_back(*(this->currentPlayer));
        this->players.erase(this->players.begin());
        this->currentPlayer = &(this->players[0]);
    } else {
        this->camera.x = - this->currentPlayer->getPosition().x;
        this->camera.y = - this->currentPlayer->getPosition().y - 0.6;
        
        bool moveable = true;
        for(int i=0; i<this->endPlayers.size(); i++){
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

        if(moveable){
            this->currentPlayer->move(direction);
        }
    }
}

void Niveau::collision(){
    for (int i = 0; i < this->players.size(); i++)
    {
        std::vector<Rectangle*> all;

        for (size_t m = 0; m < this->map.size() ; m++)
        {
            all.push_back(&(this->map[m]));
        }
        

        for (int j = 0; j < this->players.size(); j++)
        {
            if (&(this->players[j]) != &(this->players[i]))
            {
                all.push_back(&(this->players[j]));
            } 
        }

        for (size_t a = 0; a < all.size(); a++)
        {
            this->players[i].collision(all[a]);
        }
    }
}
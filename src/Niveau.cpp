#include "Niveau.hpp"

// Niveau::Niveau(Camera cam, std::vector<Rectangle> players, std::vector<Rectangle> map, float g){
//     this->camera = cam;
//     this->map = map;
//     this->gravity = g;
//     this->players = players;
// }

Niveau::Niveau(std::vector<Rectangle> players){
    this->players = players;
    this->currentPlayer = &(this->players[0]);
}

Niveau::Niveau(std::vector<Rectangle> players, std::vector<Rectangle> map, float g){
    this->players = players;
    this->currentPlayer = &(this->players[0]);
    this->map = map;
    this->gravity = g;
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
        p.y -= this->currentPlayer->getSize().y + 15;
        Triangle showPlayer(10, c, p);
        showPlayer.draw();
}

void Niveau::drawMap(){
    for(int i = 0; i<this->map.size(); i++){
        this->map[i].draw();
    }
}

void Niveau::controls(int direction){
    if(direction == 9){
        printf("Changement de joueur");
        this->players.push_back(*(this->currentPlayer));
        this->players.erase(this->players.begin());
        this->currentPlayer = &(this->players[0]);
    } else {
        this->currentPlayer->move(direction);
    }
}

void Niveau::collision(){
    glm::vec2 sideCollision;
    glm::vec2 verticalCollision;

    for (int i = 0; i < this->players.size(); i++)
    {
        std::vector<Rectangle> all = this->map;
        for (int j = 0; j < this->players.size(); j++)
        {
            if (&(this->players[j]) != &(this->players[i]))
            {
                all.push_back(this->players[j]);
            } 
        }

        verticalCollision = this->players[i].collisionVertical(all);

        if(verticalCollision.x){
        } else {
            glm::vec2 newPos(this->players[i].getPosition().x, this->players[i].getPosition().y +this->gravity*this->players[i].getWeight()/10);
            this->players[i].setPosition(newPos);
            // printf("w: %f \n", all[sideCollision.y].getWeight());
        }

    }
    
    std::vector<Rectangle> all;
        for (int j = 1; j < this->players.size(); j++)
        {
            all.push_back(this->players[j]);
        }

    sideCollision = this->currentPlayer->collisionLateral(all);

    if(sideCollision.x != 0){
        
        if(sideCollision.x == -1){
            glm::vec2 newPos(all[sideCollision.y].getPosition().x - all[sideCollision.y].getSize().x - this->currentPlayer->getSize().x, this->currentPlayer->getPosition().y);
            this->currentPlayer->setPosition(newPos);
        }
        
        if (sideCollision.x == 1){
            glm::vec2 newPos(all[sideCollision.y].getPosition().x + all[sideCollision.y].getSize().x + this->currentPlayer->getSize().x, this->currentPlayer->getPosition().y);
            this->currentPlayer->setPosition(newPos);
        }

        // printf("x: %f, y: %f \n", this->currentPlayer->getPosition().x, this->currentPlayer->getPosition().y);
        // printf("w: %f \n", all[sideCollision.y].getWeight());
    }

    
}
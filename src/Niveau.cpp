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
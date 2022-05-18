#include "Quadtree.hpp"

Quadtree::Quadtree(Rectangle* boundary){
    this->boundary = boundary;
}

void Quadtree::insert(Rectangle* element){
    // si je contiens pas l'élément, next
    if(!this->boundary->contains(element)){
        return;
    }

    if(this->collide.size()<this->max && this->isLeaf){
        this->collide.push_back(element);
    } else {
        if(this->isLeaf){
            this->subdivide();
        }

        this->upperLeft->insert(element);
        this->upperRight->insert(element);
        this->bottomLeft->insert(element);
        this->bottomRight->insert(element);

        if(this->collide.empty()) return;


        for(int i = 0; i< this->max; i++){
            this->upperLeft->insert(this->collide[i]);
            this->upperRight->insert(this->collide[i]);
            this->bottomLeft->insert(this->collide[i]);
            this->bottomRight->insert(this->collide[i]);
        }

        this->collide.erase(this->collide.begin(), this->collide.begin()+this->max);
    }
}

void Quadtree::subdivide(){
    Rectangle* upL = new Rectangle(this->boundary->getSize().x/2, this->boundary->getSize().y/2, glm::vec3(0,0,0), glm::vec2(this->boundary->getPosition().x-this->boundary->getSize().x/2, this->boundary->getPosition().y+this->boundary->getSize().y/2));
    upperLeft = new Quadtree(upL);

    Rectangle* upR = new Rectangle(this->boundary->getSize().x/2, this->boundary->getSize().y/2, glm::vec3(0,0,0), glm::vec2(this->boundary->getPosition().x+this->boundary->getSize().x/2, this->boundary->getPosition().y+this->boundary->getSize().y/2));
    upperRight = new Quadtree(upR);

    Rectangle* bL = new Rectangle(this->boundary->getSize().x/2, this->boundary->getSize().y/2, glm::vec3(0,0,0), glm::vec2(this->boundary->getPosition().x-this->boundary->getSize().x/2, this->boundary->getPosition().y-this->boundary->getSize().y/2));
    bottomLeft = new Quadtree(bL);

    Rectangle* bR = new Rectangle(this->boundary->getSize().x/2, this->boundary->getSize().y/2, glm::vec3(0,0,0), glm::vec2(this->boundary->getPosition().x+this->boundary->getSize().x/2, this->boundary->getPosition().y-this->boundary->getSize().y/2));
    bottomRight = new Quadtree(bR);

    this->isLeaf = false;
}

std::vector<Rectangle *> Quadtree::accessRightLeaf(Rectangle player){
    std::vector<Rectangle *> result;
    if(!this->boundary->contains(&player)){
        return result;
    }

    if(!this->isLeaf){
        std::vector<Rectangle *> temp;
        temp = this->upperLeft->accessRightLeaf(player);
        result.insert(result.end(), temp.begin(), temp.end());

        temp = this->upperRight->accessRightLeaf(player);
        result.insert(result.end(), temp.begin(), temp.end());

        temp = this->bottomLeft->accessRightLeaf(player);
        result.insert(result.end(), temp.begin(), temp.end());

        temp = this->bottomRight->accessRightLeaf(player);
        result.insert(result.end(), temp.begin(), temp.end());
    } else {

        for(int i = 0; i<this->collide.size(); i++){
            result.push_back(this->collide[i]);
        }

        return result;
    }
    return result;
}
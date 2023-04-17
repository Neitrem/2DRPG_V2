#pragma once

#include "Entity.h"

class Player :
    public Entity
{
private:
protected:
    //Variables

    //Initializers functions
    void initVariables();
    void initComponents();
public:
    //Constructors / Destructors
    Player(float x, float y, sf::Texture& texture);
    virtual ~Player();

    //Functions
};


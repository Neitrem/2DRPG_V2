#pragma once

#include "Entity.h"

class Player :
    public Entity
{
private:
    //Variables
    bool isAtacking;

    Weapon* weapon;


    //Initializers functions
    void initVariables();
    void initComponents();
    void initAnimations();
protected:
public:
    //Constructors / Destructors
    Player(float width, float height, float x, float y, sf::Texture& texture_sheet);
    virtual ~Player();

    //Functions
    virtual void update(const float& dt);
    void updateAnimations(const float& dt);

    void startAtack();
    void endAtack();
    void move(const float dir_x, const float dir_y, const float& dt);
};


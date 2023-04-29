#pragma once
#include <iostream>

class Weapon
{
private:
	bool* isEntityAtacking;
protected:
public:
	// Constructor / Destructor
	Weapon(bool* is_entity_atacking);
	virtual ~Weapon();
	
	//Function
	virtual void endAtack();
};


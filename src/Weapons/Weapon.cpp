#include "Weapon.h"

Weapon::Weapon(bool* is_entity_atacking)
	: isEntityAtacking(is_entity_atacking)
{
}

Weapon::~Weapon()
{
}

void Weapon::endAtack()
{
	*this->isEntityAtacking = false;
}

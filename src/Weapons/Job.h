#pragma once

#include "Weapon.h"

enum job_types {
	START_JOB = 0,
	PROCESS_JOB,
	CLEARING_JOB
};


class Job
{
public:
	// Constructor / Destructor
	Job(int job_type, Weapon* current_weapon)
	{
		this->jobType = job_type;
		this->currentWeapon = current_weapon;
	}
	virtual ~Job() {}

	// Variables
	int jobType;
	Weapon* currentWeapon;
};

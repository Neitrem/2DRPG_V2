#pragma once


enum job_types {
	START_JOB = 0,
	POCESS_JOB,
	CLEARING_JOB
};


class Job
{
public:
	// Constructor / Destructor
	Job(int job_type, void (*job_function) ())
	{
		this->jobType = job_type;
		this->jobFunction = job_function;
	}
	virtual ~Job() {}

	// Variables
	int jobType;

	// Functions
	void (*jobFunction)();
};

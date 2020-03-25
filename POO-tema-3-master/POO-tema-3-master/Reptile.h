#pragma once
#include "Vertebrate.h"
class Reptile :
	public Vertebrate
{
public:
	virtual void print() override
	{
		cout << "Reptile" << endl;
	}
	Reptile()
	{
	
	}
	~Reptile()
	{
	
	}
};


#pragma once
#include "Vertebrate.h"
class Pesti :
	public Vertebrate
{
public:
	virtual void print() override
	{
		cout << "Pesti" << endl;
	}
	Pesti()
	{
	
	}
	~Pesti()
	{
	}
};


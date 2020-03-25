#pragma once
#include "Vertebrate.h"
class Mamifere :
	public Vertebrate
{
public:
	virtual void print() override
	{
		cout << "Mamifere" << endl;
	}
	Mamifere()
	{
	}
	~Mamifere()
	{
	}
};


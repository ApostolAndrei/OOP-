#pragma once
#include<vector>
#include "Regn.h"
#include"Nevertebrate.h"
using namespace std;

template<class T>
 class AtlasZoologic
{
	 T nr;
	 vector<Regn*> lista;
public:
	AtlasZoologic()
	{
		cout << "t" << endl;
		nr = 0;
	}
	~AtlasZoologic()
	{
		for (auto p : lista)
			delete p;
	}

	void print()
	{
		cout << "Atlas:" << nr << endl;
		for (auto p : lista)
		{
			p->print();
		}
	}

	void operator +=(Regn* p)
	{
		nr++;
		lista.push_back(p);

	}
};


 template<>
 class AtlasZoologic <unsigned>
 {
	 unsigned nr;
	 vector<Regn*> lista;
 public:
	 AtlasZoologic()
	 {
		 cout << "unsigned" << endl;
		 nr = 0;
	 }
	 ~AtlasZoologic()
	 {
		  
	 }
	 void print()
	 {
		 cout << "Atlas Nevertebrate:" << nr << endl;
	 }
	 void operator +=(Regn* p)
	 {
		 if (dynamic_cast <Nevertebrate *> (p) != nullptr )
			 nr++;

	 }
 };




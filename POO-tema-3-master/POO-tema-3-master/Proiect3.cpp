#include<iostream>
using namespace std;
#include"AtlasZoologic.h"
#include"Nevertebrate.h"
#include"Reptile.h"
#include"Mamifere.h"
#include"Pasari.h"
#include"Pesti.h"



int main()

{

	AtlasZoologic<int> a;
	AtlasZoologic<unsigned> a2;

	a += new Pesti;
	a += new Reptile;

	a2 += new Pasari;
	a2 += new Mamifere;
	a2 += new Nevertebrate;


	a.print();
	a2.print();
	
}
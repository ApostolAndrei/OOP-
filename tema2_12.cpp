// ex 12

#include"pch.h"
#include <iostream>

using namespace std;

class Vector
{
	int *v;
	int dim;

public:

	Vector()
	{
		v = nullptr;
		dim = 0;
	}

	void set(int *v, int dim)
	{
		this->dim = dim;
		this->v = new int[dim];
		for (int i = 0; i < dim; i++)
			this->v[i] = v[i];
	}

	Vector(int *v, int dim) :dim(dim)
	{
		set(v, dim);
	}

	~Vector()
	{
		if (v)
			delete[]v;
	}

	int get_size()
	{
		return dim;
	}

	operator int*()
	{
		return v;
	}

	virtual void print()
	{
		for (int i = 0; i < dim; i++)
			cout << v[i] << " ";
		cout << endl;
	}
};

class Matrice
{
	Vector *m;
	int dim;
public:
	Matrice(int **a, int dim) :dim(dim)
	{
		m = new Vector[dim];
		for (int i = 0; i < dim; i++)
			m[i].set(a[i], dim);
	}

	Matrice(const Matrice &A) :dim(A.dim)
	{
		m = new Vector[dim];
		for (int i = 0; i < dim; i++)
			m[i].set(A.m[i], dim);
	}
	~Matrice()
	{
		if (m)
			delete[]m;
	}

	int get_size()
	{
		return dim;
	}

	virtual void print()
	{
		for (int i = 0; i < dim; i++)
			m[i].print();
		cout << endl;
	}
};


class Lista
{

	struct IList {
		struct nod {
			int info;
			nod *next;
		}*head;

		IList()
		{
			head = nullptr;
		}

		~IList()
		{
			nod *p = head;
			while (p)
			{
				nod *q = p;
				p = p->next;
				delete q;
			}
		}

		void print()
		{
			nod *p = head;
			while (p)
			{
				cout << p->info << " ";
				p = p->next;
			}
		}
		void insert(int x)
		{
			nod *p = new nod;
			p->info = x;
			p->next = head;
			head = p;
		}
		void operator =(const IList &L)
		{
			nod *p = L.head;
			while (p)
			{
				insert(p->info);
				p = p->next;
			}
		}
	};
	IList *list;
	int dim;

public:

	Lista(Vector *v, int dim) :dim(dim)
	{
		list = new IList[dim];
		for (int i = 0; i < dim; i++)
		{
			for (int j = 0; j < v[i].get_size(); j++)
				list[i].insert(v[i][j]);
		}
	}

	Lista(const Lista &L) : dim(L.dim)
	{
		list = new IList[dim];
		for (int i = 0; i < dim; i++)
		{
			list[i] = L.list[i];
		}
	}

	~Lista()
	{
		delete[]list;
	}


	int get_size()
	{
		return dim;
	}

	void print()
	{
		for (int i = 0; i < dim; i++)
		{
			list[i].print();
			cout << endl;
		}
	}
};

class Graf
{
	int dim;
public:
	Graf(int nr) :dim(nr)
	{

	}

	virtual ~Graf()
	{

	}

	virtual void print() = 0
	{

	}
};

class Graf_Orientat :public Graf
{

	Matrice M;

public:

	Graf_Orientat(Matrice &A) :Graf(A.get_size()), M(A)
	{

	}

	virtual ~Graf_Orientat()
	{

	}

	virtual void print()
	{
		M.print();
	}

	int* tati(int **m, int dim, int start)

	{
		int *viz = new int[dim];
		int *t = new int[dim];

		for (int i = 0; i < dim; i++)
			viz[i] = 0;

		viz[start] = 1;
		t[start] = 0;

		int k = 1, curr = start;

		while (k < dim)
		{
			for (int i = 0; i < dim; i++)
			{
				if (m[curr][i] == 1 && viz[i] == 0)
				{
					t[i] = curr;
					viz[i] = 1;
					k++;
				}
			}
			viz[curr] = 1;

			if (curr == dim - 1)
				curr = 0;
			curr++;
		}
		return t;
	}


};

class Graf_Neorientat :public Graf
{
	Lista L;
public:

	Graf_Neorientat(Lista &L) :Graf(L.get_size()), L(L)
	{

	}

	virtual ~Graf_Neorientat()
	{

	}

	virtual void print()
	{
		L.print();
	}



};


int main()
{
	int **m, n = 4;
	m = new int*[n];
	for (int i = 0; i < n; i++)
		m[i] = new int[n];


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> m[i][j];

	cout << endl;
	cout << "Matricea de adiancenta:" << endl;

	Matrice M(m, n);
	Graf_Orientat g(M);
	g.print();

	cout << "Vectorul de tati:" << endl;
	int *t = g.tati(m, 4, 1);
	for (int i = 0; i < n; i++)
		cout << t[i] << " ";


	cout <<  endl<<endl<<"Lista de adiacenta:" << endl;

	int v0[2] = { 1,2 };
	int v1[2] = { 0,2 };
	int v2[2] = { 0,1 };
	Vector *V = new Vector[n];

	V[0].set(v0, 2);
	V[1].set(v1, 2);
	V[2].set(v2, 2);
	Lista list(V, 3);
	Graf_Neorientat g2(list);
	g2.print();

	return 0;
}


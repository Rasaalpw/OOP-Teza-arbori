#include "Arbore.h"
#include <bits/stdc++.h>
using namespace std;


Node* Arbore::AdaugareFrunza(int val) {
	Node* n = new Node;
	n->val = val;
	n->st = NULL;
	n->dr = NULL;

	return n;
}

Arbore::Arbore()
{
    nr_noduri = 0;
	radacina = NULL;
}

Arbore::Arbore(const Arbore& B)
{
	this->nr_noduri = B.nr_noduri;
	this->radacina = B.radacina;
}

Arbore::~Arbore()
{
}

int Arbore::GetNrNod()
{
	return nr_noduri;
}

void Arbore::ParcurgerePre(Node* a)
{
	if (a->dr != nullptr && a->st != nullptr)
	{
		std::cout << a->val;
		ParcurgerePre(a->st);
		ParcurgerePre(a->dr);
	}
	else
		return;

}

void Arbore::ParcurgereIn(ostream& os, Node* a)
{
    if (a) {
        if (a -> st) ParcurgereIn(os, a -> st);
        os << a -> val << ' ';
        if (a -> dr) ParcurgereIn(os, a -> dr);
    }
}

void Arbore::ParcurgerePost(Node* a)
{
	if (a->dr != nullptr && a->st != nullptr)
	{
		ParcurgerePost(a->st);
		ParcurgerePost(a->dr);
		std::cout << a->val;
	}
	else
		return;
}


int Arbore::DetNivel(Node* a, int x, int nivel)
{
	if (a == NULL)
		return 0;

	if (a->val == x)
		return nivel;

	int downlevel = DetNivel(a->st, x, nivel + 1);
	if (downlevel != 0)
		return downlevel;

	downlevel = DetNivel(a->dr, x, nivel + 1);
	return downlevel;
}

void Arbore::AfisareNoduriNivel(ostream &os, int nivel)
{
    int ok = 0;
    Nivel(os, radacina, 0, nivel, ok);
    if (!ok) os << "Nivelul e mai mare decat inaltimea ABC\n";
}

void Arbore::Nivel(ostream &os, Node* a, int nivCrt, int nivel, int &ok)
{
    if (a){
        if (nivCrt == nivel) {os << a-> val << ' '; ok =1;}
        else {if (a -> st) Nivel(os, a -> st, nivCrt + 1, nivel, ok);
              if (a -> dr) Nivel(os, a -> dr, nivCrt + 1, nivel, ok);
            }
}

void Arbore::InsertNode(int x) {
    Insert(x, radacina);
}
void Arbore::Insert(int x, Node* &a)
{
    if (a == 0) {
        a = new Node;
        a -> val = x;
        a -> st = a -> dr = NULL;
    }
    else
	if (a->val < x) Insert(x, a->dr);
	else if (a->val > x) Insert(x, a->st);
        else return;
}

int Arbore::Inaltime(Node* a)
{
	if (a == NULL)
		return 0;

	else {
		// Find the height of left, right subtrees
		int left_height = Inaltime(a->st);
		int right_height = Inaltime(a->dr);

		// Find max(subtree_height) + 1 to get the height of the tree
		return max(left_height, right_height) + 1;
	}
}

istream& operator>>(istream& is, Arbore& B)
{
	int nrEl, numar;
	B.nr_noduri = 0;
	is >> nrEl;
	B.nr_noduri = nrEl;

	for (int i = 0; i < B.nr_noduri; i++)
	{
		is >> numar;
		B.Insert(numar, B.radacina);
	}
	return is;

}


ostream& operator<<(ostream& os, Arbore& B)
{
	B.ParcurgereIn(os, B.radacina);
	os << '\n';
	return os;
}


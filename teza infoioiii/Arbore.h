
#pragma once
#include<bits/stdc++.h>
using namespace std;
struct Node
	{
		int val;
		Node* st;
		Node* dr;
	};
class Arbore
{
private:
	int nr_noduri;
    Node* radacina;
    void Insert(int x, Node *&);
    void Nivel(ostream &, Node* a, int, int, int&);
public:
	Arbore();
	Arbore(const Arbore&);
	~Arbore();
	Node* AdaugareFrunza(int val);
	int GetNrNod();
	void ParcurgerePre(Node* a);
	void ParcurgereIn(ostream &, Node* a);
	void ParcurgerePost(Node* a);
	int DetNivel(Node*, int, int);
	void AfisareNoduriNivel(ostream &os, int);
	int Inaltime(Node*);
	//void AfisareFrunze();
	void InsertNode(int x);
	friend istream& operator>>(istream& is, Arbore&);
	friend ostream& operator<<(ostream& os, Arbore&);
};

#include <bits/stdc++.h>
#include "Arbore.h"
using namespace std;
ofstream fout("test.out");
int main()
{
    int v[]={5, 2, 9, 3, 1, 7, 1, 5, 8, 0};
	Arbore A;
	for (int i = 0; i < 10; ++i)
        A.InsertNode(v[i]);

	cout << A;
    A.AfisareNoduriNivel(fout, 2);

}

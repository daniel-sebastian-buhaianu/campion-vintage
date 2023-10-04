#include <fstream>
#include <algorithm>

#define NMAX 1002

using namespace std;

ifstream fin("vintage.in");
ofstream fout("vintage.out");

struct masina { int cost, valoare, nr; };

masina m[NMAX];

int v[NMAX], vmax, cmin;

bool compar(masina a, masina b);

int main()
{
	int n, k, i;

	fin >> n >> k;

	for (i = 1; i <= n; i++)
	{
		fin >> m[i].cost >> m[i].valoare;

		m[i].nr = i;
	}

	fin.close();

	sort(m+1, m+n+1, compar);

	for (i = 1; i <= k; i++)
	{
		vmax += m[i].valoare;
		cmin += m[i].cost;
		v[i] = m[i].nr;
	}

	fout << vmax << ' ' << cmin << '\n';

	for (i = 1; i <= k; i++)
	{
		fout << v[i] << ' ';
	}

	fout.close();

	return 0;
}

bool compar(masina a, masina b)
{
	if (a.valoare > b.valoare)
	{
		return 1;
	}

	if (a.valoare == b.valoare
		&& a.cost < b.cost)
	{
		return 1;
	}

	return 0;
}
// scor 100

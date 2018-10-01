#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 200001

int parent[MAXN];
vector<pair<long, pair<long, long> > >  eadgs;

long long n;

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void join(int a, int b) {
	parent[find(a)] = parent[find(b)];
}

int check(int a, int b) {
	return find(a) == find(b);
}

void Kruskal(vector<pair<long, pair<long, long> > > & result)
{
	for (int i = 0; i < n; i++)
		parent[i] = i;
	sort(eadgs.begin(), eadgs.end());

	for (auto var : eadgs)
		if (!check(var.second.first, var.second.second))
		{
			join(var.second.first, var.second.second);
			result.push_back(var);
		}
}

int main()
{
	cin >> n;
	long long e;
	cin >> e;
	long long total = 0;
	while (e)
	{
		long x, y, w;
		cin >> x >> y >> w;
		eadgs.push_back(make_pair(w, make_pair(x, y)));
		e--;
	}
	vector<pair<long, pair<long, long> > >  result;
	Kruskal(result);
	for (auto var : result)
		total += var.first;
	cout << total << endl;
	return 0;
}
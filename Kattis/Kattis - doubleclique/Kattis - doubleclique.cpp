#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <sstream>
#include <iomanip>
#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define INF 99999
#define MAXN 10000

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;


#define X first
#define Y second

#define loop(x,n) for(int x = 0; x < n; ++x)
#define foreach(x,arr) for(auto x:arr)
#define repeat(x) while(x--)
#define replaceStr(str,str1,str2) while(str.find(str1)!=-1){str.replace(str.find(str1), str1.size(), str2);}
#define eraseStr(str,str1) while(str.find(str1)!=-1){str.erase(str.find(str1), str1.size());}
#define p(x,y) make_pair(x,y)
#define distance(a1,a2) sqrt((a1.X-a2.X)*(a1.X-a2.X)+(a1.Y-a2.Y)*(a1.Y-a2.Y)) 

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
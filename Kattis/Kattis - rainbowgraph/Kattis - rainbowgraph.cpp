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
vector<pair<long, pair<long, long> > >  eadgs1;
vector<pair<long, pair<long, long> > >  eadgs2;

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

void Kruskal1(vector<pair<long, pair<long, long> > > & result)
{
	for (int i = 0; i < n; i++)
		parent[i] = i;
	sort(eadgs1.begin(), eadgs1.end());

	for (auto var : eadgs1)
		if (!check(var.second.first, var.second.second))
		{
			join(var.second.first, var.second.second);
			result.push_back(var);
		}
}

void Kruskal2(vector<pair<long, pair<long, long> > > & result)
{
	for (int i = 0; i < n; i++)
		parent[i] = i;
	sort(eadgs2.begin(), eadgs2.end());

	for (auto var : eadgs2)
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
	while (e)
	{
		long x, y, w;
		char c;
		cin >> x >> y >> w>>c;
		if(c=='R')
		{
			eadgs1.push_back(make_pair(w, make_pair(x, y)));
		}
		if(c=='B')
		{
			eadgs2.push_back(make_pair(w, make_pair(x, y)));
		}
		vector<pair<long, pair<long, long> > >  result1;
		vector<pair<long, pair<long, long> > >  result2;
		Kruskal1(result1);
		Kruskal2(result2);
		long long total1 = -1;
		long long total2 = -1;
		if (result1.size() == n || result2.size() == n )
		{
			if (result1.size() == n  )
			{
				for (auto var : result1)
					total1 += var.first;
			}
			if (result2.size() == n )
			{
				for (auto var : result2)
					total2 += var.first;
			}
			long long total = min(total2,total1);
			cout << total << endl;
		}
		else
		{
			cout << -1 << endl;
		}
		e--;
	}
	while(true);
	return 0;
}
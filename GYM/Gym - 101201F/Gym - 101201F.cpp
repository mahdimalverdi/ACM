#include <iostream>
#include <vector>
#include <string>
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
#define MAXN 1000000

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


vector<int> adj[MAXN];
vector<int> adjInv[MAXN];
bool visited[MAXN];
bool visitedInv[MAXN];
stack<int> s;
int a[MAXN], b[MAXN];


int scc[MAXN];

int counter = 1;
void dfsFirst(int u)
{
	if (visited[u])
		return;
	visited[u] = 1;
	for (int i = 0; i < adj[u].size(); i++)
		dfsFirst(adj[u][i]);
	s.push(u);
}

void dfsSecond(int u)
{
	if (visitedInv[u])
		return;
	visitedInv[u] = 1;
	for (int i = 0; i < adjInv[u].size(); i++)
		dfsSecond(adjInv[u][i]);
	scc[u] = counter;
}

bool is2Satisfiable(int n, int m)
{
	for (int i = 1; i <= 2 * n; i++)
	{
		visited[i] = false;
		visitedInv[i] = false;
		adj[i].clear();
		adjInv[i].clear();
		counter = 1;
	}
	for (int i = 0; i < m; i++)
	{
		if (a[i] > 0 && b[i] > 0)
		{
			adj[a[i] + n].push_back(b[i]);
			adjInv[b[i]].push_back(a[i] + n);
			adj[b[i] + n].push_back(a[i]);
			adjInv[a[i]].push_back(b[i] + n);
		}

		else if (a[i] > 0 && b[i] < 0)
		{
			adj[a[i] + n].push_back( n - b[i]);
			adjInv[n - b[i]].push_back(a[i] + n);
			adj[-b[i]].push_back( a[i]);
			adjInv[a[i]].push_back(-b[i]);
		}

		else if (a[i] < 0 && b[i] > 0)
		{
			adj[-a[i]].push_back( b[i]);
			adjInv[b[i]].push_back(-a[i]);
			adj[b[i] + n].push_back( n - a[i]);
			adjInv[n - a[i]].push_back(b[i] + n);
		}

		else
		{
			adj[-a[i]].push_back( n - b[i]);
			adjInv[n - b[i]].push_back(-a[i]);
			adj[-b[i]].push_back( n - a[i]);
			adjInv[n - a[i]].push_back(-b[i]);
		}
	}

	for (int i = 1; i <= 2 * n; i++)
		if (!visited[i])
			dfsFirst(i);
	while (!s.empty())
	{
		int n = s.top();
		s.pop();
		if (!visitedInv[n])
		{
			dfsSecond(n);
			counter++;
		}
	}

	for (int i = 1; i <= n; i++)
		if (scc[i] == scc[i + n])
			return false;
	return true;
}

int main()
{
	int n, r, l;
	scanf("%i%i%i", &n, &r, &l);
	int c = 0;
	std::vector<ii> v;
	int x, y;
	loop(i, l)
	{
		scanf("%i %i", &x, &y);
		v.push_back(p(x, y));
	}
	loop(i, l)
	{
		for (int j = i + 1; j < l; j++)
		{
			if (abs(v[i].Y - v[j].Y) < 2 * r + 1)
			{
				if (v[i].X == v[j].X)
				{
					a[c] = i + 1;
					b[c] = j + 1;
					c++;
				}
			}
			if (abs(v[i].X - v[j].X) < 2 * r + 1)
			{
				if (v[i].Y == v[j].Y)
				{
					a[c] = -i - 1;
					b[c] = -j - 1;
					c++;
				}

			}
		}
	}
	if (is2Satisfiable(l, c))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
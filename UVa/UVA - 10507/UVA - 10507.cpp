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

bool mat[26][26];
std::set<int> v;
int n, m;
int bfs()
{
	int sizev = 0;
	int k = 0;
	while (sizev != v.size() && v.size() != n)
	{
		k++;
		sizev = v.size();
		std::set<int> v1;

		foreach (i1, v)
		{
			v1.insert(i1);
		}
		foreach (i1, v1)
		{
			foreach (i2, v1)
			{
				if (i1 == i2)
					continue;
				foreach (i3, v1)
				{
					if (i1 == i3 || i2 == i3)
						continue;
					loop(i, 26)
					{
						if (mat[i1][i] == true && mat[i2][i] == true && mat[i3][i] == true)
							v.insert(i);
					}
				}
			}

		}

	}
	return k;
}

int main()
{
	while (scanf("%i", &n) != EOF)
	{
		loop(i, 26)
		loop(j, 26)
		mat[i][j] = false;
		v.clear();
		scanf("%i", &m);
		string str;
		cin >> str;
		v.insert(str[0] - 'A');
		v.insert(str[1] - 'A');
		v.insert(str[2] - 'A');
		repeat(m)
		{
			char s[3];
			scanf("%s", s);
			mat[s[0] - 'A'][s[1] - 'A'] = true;
			mat[s[1] - 'A'][s[0] - 'A'] = true;
		}
		int count =  bfs();
		if (v.size() == n)
			printf("WAKE UP IN, %i, YEARS\n", count );
		else
			printf("THIS BRAIN NEVER WAKES UP\n");
	}
	return 0;
}
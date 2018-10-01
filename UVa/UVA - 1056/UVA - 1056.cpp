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
#define MAXN 100

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

int mat[MAXN][MAXN];

int main()
{
	int r, p;
	int k = 1;
	while (scanf("%i %i", &p, &r) != EOF && (r | p))
	{
		std::map<string, int> mp;
		int index = 0;
		loop(i, p)
		{
			loop(j, p)
			{
				mat[i][j] = MAXN;
			}
			mat[i][i] = 0;
		}
		repeat(r)
		{
			string p1, p2;
			cin >> p1 >> p2;
			if (mp.find(p1) == mp.end())
			{
				mp[p1] = index;
				index++;
			}
			if (mp.find(p2) == mp.end())
			{
				mp[p2] = index;
				index++;
			}
			mat[mp[p1]][mp[p2]] = 1;
			mat[mp[p2]][mp[p1]] = 1;
		}
		loop(k, p)
		{
			loop(i, p)
			{
				loop(j, p)
				{
					mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
				}
			}
		}
		int maxRel = 0;

		loop(i, p)
		{
			loop(j, p)
			{
					maxRel = max(maxRel, mat[i][j]);
			}
		}
		if (maxRel != MAXN)
		{
			printf("Network %i: %i\n\n", k, maxRel);
		}
		else
		{
			printf("Network %i: DISCONNECTED\n\n", k);
		}
		k++;
	}
	return 0;
}
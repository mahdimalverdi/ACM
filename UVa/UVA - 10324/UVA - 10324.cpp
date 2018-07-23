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
#define MAXN 1000001

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

char str[MAXN];
int  eqStr[MAXN];
int main()
{
	int k = 1;
	int n;
	while (scanf("%s", &str) != EOF)
	{
		printf("Case %i:\n", k);
		k++;
		scanf("%i", &n);
		repeat(n)
		{
			int x, y;
			scanf("%i%i", &x, &y);
			eqStr[min(x, y)] = min(x, y);
			for (int i = min(x, y) + 1; i < max(x, y) + 1; i++)
			{
				if (str[i] == str[i - 1])
					eqStr[i] = eqStr[i - 1];
				else
					eqStr[i] = i;
			}
			printf("%s\n", (eqStr[max(x, y)] == eqStr[min(x, y)] ? "Yes" : "No"));
		}
	}
	return 0;
}
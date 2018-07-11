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

bool device[MAXN];
int powers[MAXN];

int main()
{
	int n , m, c;
	scanf("%i %i %i", &n, &m, &c);
	int k = 1;
	bool flag = false;
	while (n | m | c)
	{
		loop(i, n)
		{
			scanf("%i", &powers[i]);
			device[i] = false;
		}
		int power = 0;
		int maxPower = 0;
		loop(i, m)
		{
			int x;
			scanf("%i", &x);
			x--;
			device[x] = !device[x];
			if (device[x])
				power += powers[x];
			else
				power -= powers[x];
			maxPower = max(maxPower, power);
		}
		if (maxPower>c)
		{
			printf("Sequence %i\n", k);
			printf("Fuse was blown.\n");
		}
		else
		{
			printf("Sequence %i\n", k);
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %i amperes.\n", maxPower);
		}
			printf("\n");
		k++;
		scanf("%i %i %i", &n, &m, &c);
	}
	return 0;
}
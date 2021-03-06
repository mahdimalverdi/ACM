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


int main()
{
	int n;
	scanf("%i", &n);
	loop(i, n)
	{
		int x, y, z;
		scanf("%i%i%i", &x, &y, &z);
		printf("Case %i: ", i + 1);
		if (((x >= y) && (x <= z)) || ((x >= z) && (x <= y)))
			printf("%i\n", x );
		else if (((y >= x) && (y <= z)) || ((y >= z) && (y <= x)))
			printf("%i\n", y );
		else if (((z >= x) && (z <= y)) || ((z >= y) && (z <= x)))
			printf("%i\n", z );

	}
	return 0;
}
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
#define MAXN 1000000000

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
#define replaceStr(str,str1,str2) while(str.find(str1)!=-1){str.replace(str.find(str1), sizeof(str2)-1, str2);}
#define eraseStr(str,str1) while(str.find(str1)!=-1){str.erase(str.find(str1), sizeof(str1)-1);}
#define p(x,y) make_pair(x,y)

int main()
{
	int i, j;
	while (cin >> i )
	{
		cin>>j;
		printf("%i %i \n", i, j );
		if (i > j)
			swap(i, j);
		int k = i;
		int maxt = 0;
		for (; i <= j; i++)
		{
			int n = i;
			int t = 1;
			while (n != 1 )
			{
				if (n % 2 == 1)
					n = n * 3 + 1;
				else
					n /= 2;
				t++;
			}
			maxt = max(t, maxt);
		}
		printf("%i\n", maxt);
	}
	return 0;
}
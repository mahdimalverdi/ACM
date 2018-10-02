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


int main()
{
	long long z, i, m, l;
	int k = 1;
	map<int,int> mp;
	while (scanf("%lld%lld%lld%lld", &z, &i, &m, &l) != EOF && (z | i | m | l))
	{
		mp.clear();
		long long first = l;
		int j = 1;
		mp[l]=j;
		for (; (l = (z * l% m + i) % m) != first; j++){
			if(mp.find(l)!=mp.end())
			{
				j--;
				break;
			}
			mp[l]=j;
		}
		printf("Case %i: %i\n", k++, j);
	}
	return 0;
}
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

std::set<long long> v;

void dfs(int p, long long str)
{
	if (p == 0)
	{
		v.insert(str);
		return;
	}
	dfs(p - 1, str*10 + 1);
	dfs(p - 1, str*10 + 2);
}

int main()
{
	int t;
	scanf("%i", &t);
	loop(k, t)
	{
		v.clear();
		int p , q;
		scanf("%i%i", &p, &q);
		dfs(p, 0);
		bool flag = false;
		long long x = pow(2, q);
		printf("Case %i:" , k + 1 );
		long long min=99999999999999999,max=0;
		foreach (item, v)
		{
			if (item % x == 0)
			{
				if(min>item)
					min=item;
				if(max<item)
					max=item;
				flag = true;
			}
		}

		if (!flag)
			printf(" impossible");
		else
		{
			if(min==max)
			{
				printf(" %lli", min);
			}
			else 
			{
				printf(" %lli %lli", min,max);
			}
		}
		printf("\n");
	}
	return 0;
}
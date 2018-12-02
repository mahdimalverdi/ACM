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

int arr[4][MAXN];

int n;

int maxQ = 0;

int func(int last, int len, int time, int count)
{
	if(count>n)
	{
		return 0;
	}
	if (time > 280)
	{
		return 0;
	}
	loop(i, 3)
	{
		if (i == last)
			continue;
		len = max(len, func(i, len + 1, time + arr[i][count], count + 1));
	}
	len = max(len, func(4, len, time, count + 1));
	return len;
}

int main()
{
	int t;
	scanf("%i", &t);
	repeat(t)
	{
		maxQ = 0;
		scanf("%i", &n);
		loop(i, 3)
		{
			loop(j, n)
			{
				scanf("%i", &arr[i][j]);
			}
		}
		loop(j, n)
		{
			arr[3][j] = 0;
		}
		func(3, 0, 0,0);
		printf("%i\n", maxQ );
	}
	while(true);
	return 0;
}
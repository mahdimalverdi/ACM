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

int arr[MAXN];

int c = 0, n, mindepth = INF;

void dfs(int depth)
{
	if (depth > mindepth)
		return;
	bool flag = true;
	loop(i, n - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			flag = false;
			swap(arr[i], arr[i + 1]);
			dfs(depth + 1);
			swap(arr[i], arr[i + 1]);
		}
	}
	if (flag)
	{
		if (mindepth > depth)
		{
			mindepth = depth;
			c = 0;
		}
		if (mindepth > 0)
			c++;
	}
}

int main()
{
	scanf("%i", &n);
	int k = 1;
	while (n)
	{
		c = 0;
		mindepth = INF;
		loop(i, n)
		scanf("%i", &arr[i]);
		dfs(0);
		printf("There are %i swap maps for input data set %i.\n", c, k++);
		scanf("%i", &n);
	}
	while (true);
	return 0;
}
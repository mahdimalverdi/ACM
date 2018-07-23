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
#define distance(a1,a2) sqrt((a1.X-a2.X)*(a1.X-a2.X)+(a1.Y-a2.Y)*(a1.Y-a2.Y))


int main()
{
	int n, m;
	while (scanf("%i%i", &n, &m) == 2)
	{
		if (!n && !m)
			return 0;
		std::vector<ii>  times;
		bool flag = false;
		loop(i, n)
		{
			int x, y;
			scanf("%i%i", &x, &y);
			times.push_back(p(x, y));
		}
		loop(i, m)
		{
			int x, y, z;
			scanf("%i%i%i", &x, &y, &z);
			loop(i, (MAXN-x) / z + 1)
			{
				times.push_back(p(x + i * z, y + i * z));
			}
		}
		sort(times.begin(), times.end());
		loop(i, times.size() - 1)
		{
			if (times[i].Y > times[i + 1].X)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
			printf("NO CONFLICT\n");
		else
			printf("CONFLICT\n");
	}
	return 0;
}
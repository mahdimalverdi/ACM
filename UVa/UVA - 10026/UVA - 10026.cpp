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
struct cmp
{
	bool operator()(const pair<double, int> & a , const pair<double, int> & b )
	{
		if (a.X > b.X)
			return true;
		if (a.X < b.X)
			return false;
		if (a.Y > b.Y)
			return false;
		if (a.Y < b.Y)
			return true;
		return false;

	}
};

int main()
{
	int t;
	scanf("%i", &t);
	repeat(t)
	{
		string str;
		int n;
		scanf("%i", &n);

		set<pair<double, int>, cmp> s;
		loop(i, n)
		{
			int x, y;
			scanf("%i%i", &x, &y);
			s.insert(p((double)y / x, i + 1));
		}
		bool flag = false;
		foreach (item, s)
		{
			if (flag)
				printf(" ");
			flag = true;
			printf("%i", item.Y );
		}
		printf("\n");
		if (t != 0)
			printf("\n");
	}
	while (true);
	return 0;
}
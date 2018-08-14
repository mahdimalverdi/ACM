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

int p, q, r, s, t , u;
double func(double x)
{
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u ;
}
int main()
{
	while (scanf("%i%i%i%i%i%i", &p, &q, &r, &s, &t , &u) != EOF)
	{
		double ans = 100;
		bool flag = false;
		double left = 0, right = 1;
		if (func(left) < -1e-12 || func(right) > 1e-12 )
			printf("No solution\n");
		else
		{
			while (right - left > 1e-12)
			{
				double mid = (right + left) / 2;
				if (func(mid) > 0)
					left = mid;
				else
					right = mid;
			}
			printf("%.4f\n", left );
		}
	}
	while (true);
	return 0;
}
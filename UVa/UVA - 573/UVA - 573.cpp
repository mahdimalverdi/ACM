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

int main()
{
	double h, u, d, f;
	scanf("%lf %lf %lf %lf", &h, &u, &d, &f);
	while (h)
	{
		f=(f/100)*u;
		double i = 0;
		int day =0;
		while (++day)
		{
			if((i += u)>h || (i -= d)<0)
				break;
			u = max(0.0,u-f);
		}
		if (i >= h)
			printf("success on day %i\n", day);
		else
			printf("failure on day %i\n", day);
		scanf("%lf %lf %lf %lf", &h, &u, &d, &f);
	}
	return 0;
}
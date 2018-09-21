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
#define MAXN 100000

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
	int t;
	scanf("%i", &t);
	loop(k, t)
	{
		int n;
		scanf("%i", &n);
		int sum = 0;
		int maxPath = 0;
		int start = 0, end = 0, newstart = 0;
		for(int i=1;i<n;i++)
		{
			int x;
			scanf("%i", &x);
			sum += x;
			if (sum > maxPath || (sum == maxPath && end-start<i-newstart))
			{
				maxPath = sum;
				start = newstart;
				end = i;
				cout<<"+"<<maxPath<<endl;
			}
			if (sum < 0)
			{
				sum = 0;
				newstart = i;
			}
			cout << i << " " << sum << " " << maxPath << endl;
		}
		if (maxPath > 0)
		{
			printf("The nicest part of route %i is between stops %i and %i\n", k + 1, start+1 , end+1 );
		}
		else
		{
			printf("Route %i has no nice parts\n", k + 1 );
		}
	}
	return 0;
}
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

int arr[MAXN];

int main()
{
	int t;
	scanf("%i", &t);
	loop(i, t)
	{
		int n;
		scanf("%i", &n);
		int maxB=0;
		int last=0;
		loop(j,n)
		{
			scanf("%d", &arr[j]);
			maxB=max(maxB,arr[j]-last);
			last=arr[j];
		}
		int result=maxB;
		loop(j,n)
		{
			if(maxB==arr[j]-arr[j-1])
			{
				maxB--;
			}
			else if(maxB<arr[j]-arr[j-1])
			{
				result++;
				break;
			}
		}
		printf("Case %d: %d\n",i+1,result );
	}
	return 0;
}
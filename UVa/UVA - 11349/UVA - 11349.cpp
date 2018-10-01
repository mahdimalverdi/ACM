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
#define MAXN 102

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

long long mat[MAXN][MAXN];

int main()
{
	int t;
	scanf("%i",&t);
	loop(k,t)
	{
		int n;
		scanf("\nN = %i",&n);
		loop(i,n)
		{
			loop(j,n)
			{
				scanf("%lld",&mat[i][j]);
			}
		}
		bool flag=true;
		loop(i,n)
		{
			loop(j,n)
			{
				if(mat[i][j]!=mat[n-1-i][n-1-j] || mat[i][j]<0)
				{
					flag=false;
				}
			}
		}
		if(flag)
		{
			printf("Test #%i: Symmetric.\n",k+1);
		}
		else
		{
			printf("Test #%i: Non-symmetric.\n",k+1);
		}

	}
	return 0;
}
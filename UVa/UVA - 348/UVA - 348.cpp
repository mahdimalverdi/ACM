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

#define INF 9223372036854775807
#define MAXN 12

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

int columns[MAXN];
int rows[MAXN];

long long mat[MAXN][MAXN];
int minK[MAXN][MAXN];

string order(int i,int j)
{
	if(i==j)
	{
		return "A"+to_string(i+1);
	}
	else
	{
		return "("+order(i,minK[i][j])+" x "+order(minK[i][j]+1,j)+")";
	}
}

int main()
{
	int n,m=1;
	while (scanf("%i", &n) != EOF && n!=0)
	{
		loop(i, n)
		{
			scanf("%i%i", &columns[i], &rows[i]);
		}
		loop(i, n)
		{
			mat[i][i] = 0;
			minK[i][i]=-1;
		}
		for (int l = 1; l < n; l++)
		{
			loop(i, n - l)
			{
				int j = l + i;
				mat[i][j] = INF;
				for (int k = i; k < j; k++)
				{
					long long amount = mat[i][k] + mat[k + 1][j] + columns[i] * rows[k] * rows[j];
					if (amount < mat[i][j])
					{
						mat[i][j] = amount;
						minK[i][j] = k;
					}
				}
			}
		}
		printf("Case %i: %s\n",m++,order(0,n-1).c_str() );
	}
	return 0;
}
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


int main()
{
	int arr[45];
	int n;
	scanf("%i", &n);
	repeat(n)
	{
		int k = 0;
		for (int i = 0; i < 9; i += 2)
		{
			for (int j = 0; j <= i; j += 2)
			{
				scanf("%i", &arr[k + j]);
			}
			k += 2 * i + 3;
		}
		k = 0;
		for (int i = 0; i < 7; i += 2)
		{
			for (int j = 0; j <= i; j += 2)
			{
				arr[k + j + 2 * i + 4] = (arr[k + j] - arr[k + j + 2 * i + 3] - arr[k + j + 2 * i + 5]) / 2;
			}
			k += 2 * i + 3;
		}
		k = 1;
		for (int i = 1; i < 8; i += 2)
		{
			for (int j = 0; j <= i; j++)
			{
				arr[k + j] = (arr[k + i + j + 1] + arr[k + i + j + 2]);
			}
			k += 2 * i + 3;
		}
		k = 0;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (j != 0)
					printf(" ");
				printf("%i", arr[k + j] );
			}
			printf("\n");
			k += i + 1;
		}
	}
	return 0;
}
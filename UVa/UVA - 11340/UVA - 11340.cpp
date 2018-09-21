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
#define MAXN 10001

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

char characters[MAXN];
int amounts[MAXN];
char str[MAXN];
int main()
{
	int t;
	scanf("%i", &t);
	repeat(t)
	{
		int n;
		int amount=0;
		scanf("%i", &n);
		loop(i, n)
		{
			cin>>characters[i];
			cin>>amounts[i];
		}
		int m;
		scanf("%i", &m);
			gets(str);
		loop(i, m)
		{
			gets(str);
			loop(j, n)
			{
				amount+= count(str,str+strlen(str),characters[j])*amounts[j];
			}
		}
		printf("%.2f$\n",amount/100.0);
	}
	return 0;
}
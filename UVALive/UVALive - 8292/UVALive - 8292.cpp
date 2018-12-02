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
#define MOD 1000000007

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

double num = 0.141592653589793238;




int main()
{
	int n;
	scanf("%i", &n);
	repeat(n)
	{
		int s1 = 1, s2 = 1, m1 = 1, m2 = 1;
		int k, maxNum;
		scanf("%i%i%lf", &k, &maxNum, &num);

		m1=ceil(1/num);
		m2=m1-1;

		while (m1 + m2 < maxNum)
		{
			if ((s1 + s2) / ((double)(m1 + m2)) > num)
			{
				s2 += s1;
				m2 += m1;
			}
			else
			{
				s1 += s2;
				m1 += m2;
			}
		}
		if (fabs(num - s2 / (double)m2) < fabs(num - s1 / (double)m1))
		{
			printf("%i %i/%i\n", k, s2, m2 );
		}
		else
		{
			printf("%i %i/%i\n", k, s1, m1 );
		}
	}
	return 0;
}
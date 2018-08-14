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

int getDis(ii left, ii right)
{
	return right.X * 60 + right.Y - left.X * 60 - left.Y;
}

int main()
{
	int n;
	int day = 0;
	while (scanf("%i", &n) != EOF)
	{
		bool arr[24 * 60];
		loop(i, 24 * 60)
		{
			arr[i] = false;
		}
		loop(i, 10 * 60)
		{
			arr[i] = true;
		}
		loop(i, 6 * 60)
		{
			arr[i + 18 * 60] = true;
		}
		repeat(n)
		{
			int h1, h2, m1, m2;
			char a[3], b[3];
			scanf("%i:%s %i:%s", &h1, &a, &h2, &b);
			m1 = (a[0] - '0') * 10 + a[1] - '0';
			m2 = (b[0] - '0') * 10 + b[1] - '0';
			loop(i, h2 * 60 + m2 - h1 * 60 - m1)
			{
				arr[h1 * 60 + m1+i] = true;
			}
			string str;
			getline(cin, str);
		}
		int maxNap = 0;
		int nap = 0, start = 0,lastStart;
		loop(i, 24 * 60)
		{
			if (arr[i] == false)
			{
				nap++;
			}
			else
			{
				if (maxNap < nap)
				{
					maxNap = nap;
					start = lastStart;
				}
				lastStart=i+1;
				nap = 0;
			}
		}
		day++;
		printf("Day #%i: the longest nap starts at %i:%i%i and will last for ", day, start / 60, start % 60 / 10, start % 60 % 10 );
		if (maxNap >= 60)
		{
			printf("%i hours and ", maxNap / 60 );
		}
		printf("%i minutes.\n", maxNap % 60 );

	}
	return 0;
}
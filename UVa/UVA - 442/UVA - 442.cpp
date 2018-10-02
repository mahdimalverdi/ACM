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
	int n;
	scanf("%i", &n);
	map<char, ii> mp;
	repeat(n)
	{
		char name;
		int x, y;
		cin >> name >> x >> y;
		mp[name] = p(x, y);
	}
	string str;
	while (cin >> str)
	{
		stack<ii> matrixes;
		bool error = false;
		int count = 0;
		loop(i, str.size())
		{
			if (str[i] == '(')
			{

			}
			else if (str[i] == ')')
			{
				pair<int, int> p1 = matrixes.top();
				matrixes.pop();
				pair<int, int> p2 = matrixes.top();
				matrixes.pop();
				if (p1.X != p2.Y)
				{
					error = true;
					break;
				}
				count += p2.X * p2.Y * p1.Y;
				matrixes.push(p(p2.X, p1.Y));
			}
			else
			{
				matrixes.push(mp[str[i]]);
			}
		}
		if (error)
		{
			printf("error\n");
		}
		else
		{
			printf("%i\n",count);
		}
	}
	return 0;
}
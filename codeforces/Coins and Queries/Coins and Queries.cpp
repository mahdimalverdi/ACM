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
#define MAXN 200000

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
#define replaceStr(str,str1,str2) while(str.find(str1)!=-1){str.replace(str.find(str1), sizeof(str2)-1, str2);}
#define eraseStr(str,str1) while(str.find(str1)!=-1){str.erase(str.find(str1), sizeof(str1)-1);}
#define p(x,y) make_pair(x,y)

std::map<int, int, greater<int>> mp;

int main()
{
	int n, q;
	scanf("%i %i", &n, &q);
	loop(i, n)
	{
		int x;
		scanf("%i", &x);
		mp[x]++;
	}
	string str = "";
	repeat(q)
	{
		int x;
		scanf("%i", &x);
		int sum = 0;
		int count = 0;
		foreach (item, mp)
		{
			count += min((x - sum) / item.X, item.Y);
			sum += item.X * min((x - sum) / item.X, item.Y);
		}
		if (sum == x)
			str += to_string(count) + "\n";
		else
			str += "-1\n";

	}
	printf("%s", str.c_str());
	return 0;
}
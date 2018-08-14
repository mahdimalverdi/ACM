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
	std::vector<pair<string, int>> v;
	string str;
	cin >> str;
	while (str != "#")
	{
		loop(i, 52)
		{
			v.push_back(p(str, 1));
			cin >> str;
		}
		bool flag = true;
		while (flag)
		{
			flag = false;
			for (int i = 1; i < v.size(); i++)
			{
				if (v[i].X[0] == v[i - 1].X[0])
				{
					flag = true;
					v[i - 1].X = v[i].X;
					v[i - 1].Y += v[i].Y;
					v.erase(v.begin() + i);
					break;
				}
				else if (v[i].X[1] == v[i - 1].X[1])
				{
					flag = true;
					v[i - 1].X = v[i].X;
					v[i - 1].Y += v[i].Y;
					v.erase(v.begin() + i);
					break;
				}
				else if (i >  2)
				{
					if (v[i].X[0] == v[i - 3].X[0])
					{
						flag = true;
						v[i - 3].X = v[i].X;
						v[i - 3].Y += v[i].Y;
						v.erase(v.begin() + i);
						break;
					}
					else if (v[i].X[1] == v[i - 3].X[1])
					{
						flag = true;
						v[i - 3].X = v[i].X;
						v[i - 3].Y += v[i].Y;
						v.erase(v.begin() + i);
						break;
					}
				}
			}

			foreach (item, v)
				printf("%s ", item.X.c_str() );
			printf("\n");
		}
		foreach (item, v)
			printf("%s %i\n", item.X.c_str() , item.Y);
		v.clear();
	}
	while (true);
	return 0;
}
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
#define replaceStr(str,str1,str2) while(str.find(str1)!=-1){str.replace(str.find(str1), sizeof(str1)-1, str2);}
#define eraseStr(str,str1) while(str.find(str1)!=-1){str.erase(str.find(str1), sizeof(str1)-1);}
#define p(x,y) make_pair(x,y)

map<string, int> arraies;
map<string, int> size_of_arraies;
map<string, int> dimension_of_arraies;
std::map<string, std::vector<int>> lowerbounds_dimension_of_arraies;
std::map<string, std::vector<int>> upperbounds_dimension_of_arraies;

int Cs[MAXN];

int main()
{
	int n, r;
	scanf("%i %i", &n, &r);
	loop(i, n)
	{
		string name;
		cin >> name;
		int B, CD, D;
		scanf("%i %i %i", &B, &CD, &D);
		arraies[name] = B;
		size_of_arraies[name] = CD;
		dimension_of_arraies[name] = D;
		loop(j, D)
		{
			int l, u;
			scanf("%i %i", &l, &u);
			lowerbounds_dimension_of_arraies[name].push_back(l);
			upperbounds_dimension_of_arraies[name].push_back(u);
		}
	}
	loop(i, r)
	{
		string name;
		cin >> name;
		std::vector<int> v;
		loop(i, dimension_of_arraies[name])
		{
			int x;
			scanf("%i", &x);
			v.push_back(x);
		}
		printf("%s[", name.c_str());
		bool flag = false;
		foreach (item, v)
		{
			if (flag)
				printf(", ");
			flag = true;
			printf("%i", item);
		}
		printf("] = ");
		int result = 0;
		Cs[dimension_of_arraies[name]] = size_of_arraies[name];
		Cs[0] = arraies[name] - Cs[dimension_of_arraies[name]] * lowerbounds_dimension_of_arraies[name][dimension_of_arraies[name] - 1];
		result += Cs[dimension_of_arraies[name]] * v[dimension_of_arraies[name] - 1];
		for (int j = dimension_of_arraies[name] - 1; j > 0; j--)
		{
			Cs[j] = Cs[j + 1] * (upperbounds_dimension_of_arraies[name][j] - lowerbounds_dimension_of_arraies[name][j] + 1);
			Cs[0] -= Cs[j] * lowerbounds_dimension_of_arraies[name][j - 1];
		}
		result += Cs[0];
		loop(j, dimension_of_arraies[name] - 1)
		result += Cs[j + 1] * v[j];
		printf("%i\n", result);
	}
	return 0;
}
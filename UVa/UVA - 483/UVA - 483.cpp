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
#define MAXN 100

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
#define eraseStr(str,str1) while(str.find(str1)!=-1){str.erase(str.find(str1), sizeof(str1)-1);}
#define p(x,y) make_pair(x,y)

int main()
{
	string str;
	while (getline(cin, str))
	{
		stringstream ss(str);
		string s;
		int fstr = 0;
		while (ss >> s)
		{
			string cpy = s;
			reverse(cpy.begin(), cpy.end());
			str.replace(str.find(s, fstr), s.size() , cpy);
			fstr += s.size();
		}
		printf("%s", str.c_str());
		if (!cin.eof())
			printf("\n");
	}
	return 0;
}
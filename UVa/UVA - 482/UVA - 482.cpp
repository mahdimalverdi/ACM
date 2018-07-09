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

string arr[MAXN];

int main()
{
	int t;
	cin >> t;
	cin.ignore();
	repeat(t)
	{
		string str;
		cin.ignore();
		getline(cin, str);
		stringstream ss1(str);
		std::vector<int> v1;
		std::vector<string>  v2;
		int x;
		while (ss1 >> x)
		{
			v1.push_back(x);
		}
		getline(cin, str);
		stringstream ss2(str);
		string d;
		while (ss2 >> d)
		{
			v2.push_back(d);
		}
		int n = v1.size();
		loop(i, n)
		{
			arr[v1[i] - 1] = v2[i];
		}
		loop(i, n)
		{
			cout << arr[i] << endl;
		}
		if (t != 0)
			cout << endl;
	}
	return 0;
}
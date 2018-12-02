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

string strs[20]{
"2 2 1 0",
"11 16 8 4",
"44 92 50 24",
"189 512 284 144",
"798 2654 1499 776",
"3383 13344 7620 4004",
"14328 65368 37636 19984",
"60697 314432 182152 97472",
"257114 1490842 867829 467184",
"1089155 6988464 4083824 2208996",
"4613732 32455028 19026102 10331624",
"19544085 149560640 87910532 47892112",
"82790070 684716086 403380367 220355000"};

int main()
{
	int n;
	scanf("%i",&n);
	loop(i,n)
	{
		int k,x;
		scanf("%i%i",&k,&x);
		cout<<k<<" "<<strs[x-1]<<endl;
	}
	return 0;
}
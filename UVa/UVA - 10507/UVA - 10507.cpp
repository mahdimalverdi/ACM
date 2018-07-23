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

bool mat[26][26];
map<int,set<int>> mp;
int dfs(int i,int depth)
{
	mp[depth].insert(i);
	int maxc=0;
	loop(j,26)
	{
		if(mat[i][j])
			maxc=max(dfs(j,depth+1),maxc);
	}
}

int main()
{
	int n,m;
	while(scanf("%i",&n)!=EOF)
	{
		loop(i,26)
			loop(j,26)
				mat[i][j]=false;
		scanf("%i",&m);
		string str;
		cin>>str;
		repeat(m)
		{
			char s[3];
			scanf("%s",s);
			mat[s[0]-'A'][s[1]-'A']=true;
			mat[s[1]-'A'][s[0]-'A']=true;
		}
		int count=0;
		dfs(str[0]-'A',0);
		dfs(str[1]-'A',0);
		dfs(str[2]-'A',0);
		foreach(item,mp)
		{
		cout<<item.Y.size()<<endl;
			if(item.Y.size()==n)
				count++;
		}
		if(count)
			printf("WAKE UP IN, %i, YEARS\n",count );
		else
			printf("THIS BRAIN NEVER WAKES UP\n");
	}
	while (true);
	return 0;
}
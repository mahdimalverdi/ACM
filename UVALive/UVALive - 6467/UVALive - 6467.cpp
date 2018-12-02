#include <bits/stdc++.h>
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

map<int,std::vector<int>> mp1;
map<int,std::vector<int>> mp2;

int dfs(int i)
{
	if(mp2[i].size()==0)
	{
		return 1;
	}
	else
	{
		int maxdis=0;
		foreach(item,mp2[i])
		{
			maxdis=max(maxdis,dfs(item)+1);
		}
		return maxdis;
	}
}

int main()
{
	int t;
	scanf("%i",&t);
	repeat(t)
	{
		int k,m,p;
		mp1.clear();
		mp2.clear();
		scanf("%i%i%i",&k,&m,&p);
		loop(i,p)
		{
			int x,y;
			scanf("%i%i",&x,&y);
			mp1[x].push_back(y);
			mp2[y].push_back(x);
		}
		int maxdis=0;
		foreach(item,mp1)
		{
			if(item.Y.size()==0)
			{
				maxdis=max(maxdis,dfs(item.X)+1);
			}
		}
		printf("%i %i\n",k,maxdis );
	}
	while (true);
	return 0;
}
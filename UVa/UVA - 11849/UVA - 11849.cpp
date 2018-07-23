#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <sstream>
#include <iomanip>
using namespace std;

#define INF 99999
#define MAXN 100

#define X first
#define Y second

#define loop(x,n) for(int x = 0; x < n; ++x)
#define foreach(x,arr) for(auto x:arr)
#define repeat(x) while(x--)
#define replaceStr(str,str1,str2) while(str.find(str1)!=-1){str.replace(str.find(str1), sizeof(str2)-1, str2);}
#define eraseStr(str,str1) while(str.find(str1)!=-1){str.erase(str.find(str1), sizeof(str1)-1);}
#define p(x,y) make_pair(x,y)

int main()
{
	int m,n;
	cin>>m>>n;
	while(m|n)
	{
		map<int,int> mp;
		repeat(m)
		{
			int x;
			cin>>x;
			mp[x]++;
		}
		repeat(n)
		{
			int x;
			cin>>x;
			mp[x]++;
		}
		int count=0;
		foreach(item,mp)
		{
			if(item.second!=1)
			{
				count++;
			}
		}
		cout<<count<<endl;
		cin>>m>>n;
	}
	return 0;
}
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
	int n;
	cin>>n;
	while(n)
	{
		priority_queue<long long,vector<long long>,greater<long long>> l;
		repeat(n)
		{
			int x;
			cin>>x;
			l.push(x);
		}
		long long cost=0;
		long long last=0;
		while(l.size()>1)
		{
			last=l.top();
			l.pop();
			last+=l.top();
			l.pop();
			l.push(last);
			cost+=last;
		}
		cout<<cost<<endl;
		cin>>n;
	}
	return 0;
}
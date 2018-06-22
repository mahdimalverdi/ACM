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
#define MAXN 2000

#define X first
#define Y second

#define loop(x,n) for(int x = 0; x < n; ++x)
#define foreach(x,arr) for(auto x:arr)
#define repeat(x) while(x--)
#define replaceStr(str,str1,str2) while(str.find(str1)!=-1){str.replace(str.find(str1), sizeof(str2)-1, str2);}
#define eraseStr(str,str1) while(str.find(str1)!=-1){str.erase(str.find(str1), sizeof(str1)-1);}
#define p(x,y) make_pair(x,y)

string strings[MAXN];

int main()
{
	int n,q;
	cin>>n;
	loop(i,n)
		cin>>strings[i];
	cin>>q;
	loop(i,q)
	{
		string x;
		cin>>x;
		cout<<count(strings, strings+n,x)<<(i!=q-1?"\n":"");
	}
	return 0;
}
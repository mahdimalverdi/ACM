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
#define MAXN 100000

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
	int n , q;
	std::vector<int> seqList[MAXN];
	cin>>n>>q;
	int lastAnswer = 0;
	repeat(q)
	{
		int a, x, y;
		cin >> a >> x >> y;
		x = (x ^ lastAnswer) % n;
		if (a == 1)
		{
			seqList[x].push_back(y);
		}
		else if (a == 2)
		{
			lastAnswer=seqList[x][y%seqList[x].size()];
			cout<<lastAnswer<<endl;
		}
	}
	while (true);
	return 0;
}
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
using namespace std;

#define INF 99999
#define MAXN 33554500

#define X first
#define Y second

#define loop(x,n) for(int x = 0; x < n; ++x)
#define foreach(x,arr) for(auto x:arr)
#define repeat(x) while(x--)
#define replaceStr(str,str1,str2) while(str.find(str1)!=-1){str.replace(str.find(str1), sizeof(str2)-1, str2);}
#define eraseStr(str,str1) while(str.find(str1)!=-1){str.erase(str.find(str1), sizeof(str1)-1);}
#define p(x,y) make_pair(x,y)

long arr[MAXN], maxsum = 0;
int n, q;
int maxn;

int a, b, x;

int main()
{
	cin >> n >> q;
	repeat(q)
	{
		cin >> a >> b >> x;
		arr[a-1] += x;
		arr[b] -= x;
	}
	long x=0;
	loop(i, n)
	{
		x+=arr[i];
		maxsum=max(maxsum,x);
	}
	cout << maxsum << endl;
	return 0;
}
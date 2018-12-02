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


int main()
{
	int n;
	string str1,str2;
	cin>>n>>str1>>str2;
	int m=0;
	loop(i,str1.size())
	{
		if(str1[i]==str2[i])
		{
			m++;
		}
	}
	int non=str1.size()-m;
	int result=0;
	if(non==0)
	{
		result=max(result,n);
	}
	if(m==0)
	{
		result=max(result,non-n);
	}
	if(m>=n)
	{
		result=max(result,non+n);
	}
	if(m<n)
	{
		result=max(result,m+non-n+m);
	}
	cout<<result<<endl;
	return 0;
}
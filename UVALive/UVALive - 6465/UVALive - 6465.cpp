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
	int t;
	scanf("%i", &t);
	repeat(t)
	{
		int k;
		int arr[15];
		scanf("%i", &k);
		loop(i, 15)
		{
			scanf("%i", &arr[i]);
		}
		int count = 0;
		loop(i, 15)
		{
			if (arr[i] == 0)
				continue;
			int tmp=arr[i];
			loop(j, 15 - i)
			{
				if (arr[j + i] < tmp)
				{
					break;
				}
				if (arr[j + i] == tmp)
				{
					arr[j + i] = 0;
				}
			}
			count++;
			arr[i] == 0;
		}
		printf("%i %i\n", k, count );
	}
	return 0;
}
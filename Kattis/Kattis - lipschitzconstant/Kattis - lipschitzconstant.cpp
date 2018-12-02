#include <bits/stdc++.h>
using namespace std;

#define INF 99999
#define MAXN 200100
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


pair<double, double> arr[MAXN];
int main()
{
	int n;
	scanf("%i", &n);
	loop(i, n)
	{
		double x, y;
		scanf("%lf %lf", &x, &y);
		arr[i] = p(x, y);
	}
	sort(arr, arr + n);
	double ans = fabs(arr[1].Y - arr[0].Y) / fabs(arr[1].X - arr[0].X);
	loop(i, n - 1)
	{
		ans = max(ans, fabs(arr[i + 1].Y - arr[i].Y) / fabs(arr[i + 1].X - arr[i].X));
	}
	printf("%.6f\n", ans );
	while (true);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define INF 99999
#define MAXN 100
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
    ll a[MAXN] = {0}, c[MAXN][MAXN] = {0};
    a[0] = a[1] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        a[i] = a[i - 1] * i;
    }
    c[0][0] = 1;
    for(int i=1;i<MAXN;i++)
    {
        c[i][0] = 1;
        for(int j=1;j<=i;j++)
        {
            c[i][j] = c[i-1][j-1]+c[i-1][j];
        }
    }
    int t;
    scanf("%i",&t);
    repeat(t)
    {
        int k1, n,k;
        scanf("%i %i %i",&k1,&n,&k);
        ll ans=a[n];
        for(int i=1;i<=k;i++)
        {
            if(i%2==1)
            {
                ans-=c[k][i]*a[n-i];
            }
            else
            {
                ans+=c[k][i]*a[n-i];
            }
        }
        cout<<k1<<" "<<ans<<endl;
    }
    return 0;
}

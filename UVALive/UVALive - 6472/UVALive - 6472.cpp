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

long long choose(int n,int r)
{
    r=min(r,n-r);
    long long result=1;
    for(int i=0;i<n;i++)
    {
        if(i<=r && i>0)
        {
            result/=(i);
        }
        if(i<=r-1)
        {
            result*=(n-i);
        }
        if(i>r && i>r-1)
        {
            break;
        }
    }
    return result;
}

long long llpow(int n,int p)
{
    if(p==0)
        return 1;
    return n * llpow(n,p-1);
}

int main()
{
    int t;
    scanf("%i",&t);
    repeat(t)
    {
        int k,n,i,j;
        scanf("%i %i %i %i",&k,&n,&i,&j);
        printf("%i %lld\n",k,llpow(n,i-j)*choose(i,j) );
    }
    return 0;
}

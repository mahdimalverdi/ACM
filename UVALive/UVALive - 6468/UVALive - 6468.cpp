#include <bits/stdc++.h>
using namespace std;

#define INF 99999
#define MAXN 100000000
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

map<int,int> mp;

ll func(int j)
{

    int a = 1;
    int b = 1;
    for (int i=2; i<MAXN;i++)
    {
        a = a+b;
        swap(a,b);
        a=a%j;
        b=b%j;
        if(a==1 and b==1)
        {
            return i-1;
        }

    }
}

int main()
{
    int t;
    scanf("%i",&t);
    repeat(t)
    {
        int k,n;
        scanf("%i %i",&k,&n);
        printf("%i %lld\n",k,func(n));
    }

    return 0;
}

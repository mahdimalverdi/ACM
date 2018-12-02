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
    double mindis=MAXN;
    int gx,gy;
    int a,b,c,d;
    cin>>gx>>gy;
    cin>>a>>b>>c>>d;

    if(c<a)
    {
        swap(a,c);
    }
    else if(d<b)
    {
        swap(d,b);
    }
    
    if(gx<a && gy<b )
    {
        mindis=min(distance(p(gx,gy),p(a,b)),mindis);
    }
    else if(gx<a && gy>d )
    {
        mindis=min(distance(p(gx,gy),p(a,d)),mindis);
    }
    else if(gx>c && gy<b )
    {
        mindis=min(distance(p(gx,gy),p(c,b)),mindis);
    }
    else if(gx>c && gy>d )
    {
        mindis=min(distance(p(gx,gy),p(c,d)),mindis);
    }
    else if(gy<=b)
    {
        mindis=min(distance(p(gx,gy),p(gx,b)),mindis);
    }
    else if(gy>=d)
    {
        mindis=min(distance(p(gx,gy),p(gx,d)),mindis);
    }
    else if(gx<=a)
    {
        mindis=min(distance(p(gx,gy),p(a,gy)),mindis);
    }
    else if(gx>=c)
    {
        mindis=min(distance(p(gx,gy),p(c,gy)),mindis);
    }



    printf("%.4f\n", mindis);
    return 0;
}

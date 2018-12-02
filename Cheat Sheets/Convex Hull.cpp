#include <bits/stdc++.h>
using namespace std;

#define INF 99999
#define MAXN 1000
#define MAXDIS 1000000
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

vector<double> x;
vector<double> y;

double shortest_distance(double a, double b,
                         double c,
                         double x1, double y1
                        )
{
    double d = fabsl((a * x1 + b * y1 + c)) /
               (sqrt(a * a + b * b));

    return d;
}

void func2(double & a, double &b, double &c, int i, int n)
{
    if (x[(i + 1) % n] == x[i % n])
    {
        a = 1;
        b = 0;
        c = x[i % n];
    }
    else if (y[(i + 1) % n] == y[i % n])
    {
        a = 0;
        b = 1;
        c = y[i % n];
    }
    else
    {
        a = (y[(i + 1) % n] - y[i % n]) / ( x[(i + 1) % n] - x[i % n] );
        b = -1;
        c = y[i % n] - a * x[i % n];
    }
}

double getangle(double x, double y)
{
    double p = asin(1) * 2;
    double result = 0;
    if (y == 0 && x >= 0)
    {
        result = 0;
    }
    else if (y == 0 && x < 0)
    {
        result = p;
    }
    else if (x == 0 && y > 0)
    {
        result = p / 2;
    }
    else if (x == 0 && y < 0)
    {
        result = 3 * p / 2;
    }
    else if (x > 0 && y > 0)
    {
        result = atan(y / x);
    }
    else if (x < 0 && y > 0)
    {
        result = atan(y / x) + p;
    }
    else if (x < 0 && y < 0)
    {
        result = atan(y / x) + p;
    }
    else if (x > 0 && y < 0)
    {
        result = atan(y / x) + 2 * p;
    }
    result = result * 180 / p;
    return result;
}

int main()
{
    vector<double> xtmp;
    vector<double> ytmp;
    int n;
    scanf("%i", &n);
    double maxdis = MAXDIS;
    x.resize(n);
    y.resize(n);
    xtmp.resize(n);
    ytmp.resize(n);
    int x1 = -100000, y1 = -100000, pi = 0;
    loop(i, n)
    {
        cin >> xtmp[i] >> ytmp[i];
        if (y1 == y[i] && x1 < x[i])
        {
            x1 = xtmp[i];
            y1 = ytmp[i];
            pi = i;
        }
        else if (y1 < ytmp[i])
        {
            x1 = xtmp[i];
            y1 = ytmp[i];
            pi = i;
        }
    }
    vector <pair<double,int>> v;
    loop(i, n)
    {
        double angle = getangle(xtmp[i] - xtmp[pi] , ytmp[i] - ytmp[pi] );
        v.push_back(p(angle,i));
    }
    sort(v.begin(),v.end());
    int kj=0;
    foreach(item, v)
    {
        int i=item.Y;
        x[n-kj-1] = (xtmp[i]);
        y[n-kj-1] = (ytmp[i]);
        kj++;
    }
    double last = 0;
    int s = n;
    bool flag = true;

    while (flag)
    {
        flag = false;
        loop(i, n - 1)
        {
            int k = i;
            double angle1 = getangle(x[(k) % n] - x[(k - 1+n) % n] , y[(k) % n] - y[(k - 1+n) % n] );
            double angle2 = getangle(x[(k + 1 + n) % n] - x[(k ) % n] , y[(k + 1 + n) % n] - y[(k ) % n] );
            if (angle1   < angle2  )
            {
                n--;
                i--;
                x.erase(x.begin() + (k) % n);
                y.erase(y.begin() + (k) % n);
                flag = true;
                break;
            }
        }
    }
    loop(i, n)
    {
        int k = i;
        double dis = 0;
        double a, b, c;
        k = i;
        func2(a, b, c, k, n);
        loop(j, n)
        {
            double r = shortest_distance(a, b, c, x[j], y[j]);
            if (r > dis)
                dis = r;
        }
        maxdis = min(dis, maxdis);
    }
    printf("%llf\n", maxdis);
    return 0;
}

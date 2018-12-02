#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <sstream>
#include <iomanip>
#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define INF 99999
#define MAXN 1000006

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


int nextNodes[MAXN];


int main()
{
    map<int,int> entekhab;
    int n, m;
    map<string,int>  strs;
    scanf("%i%i", &n, &m);
    std::vector<string>  s;
    int r=1;
    for(int i=n-m;i<n;i++)
    {
        entekhab[i]=r;
        r*=i+1;
    }
    loop(i, n)
    {
        string str;
        cin >> str;
        s.push_back(str);
    }
    sort(s.begin(),s.end());
    int k=0;
    foreach (item, s) {
        strs[item]=k++;
    }
    string tmp="";
    string strTmp;
    cin >> strTmp;
    int mj=1;
    int result=0;
    set<int> v;
    for(int i=0;i<strTmp.size();i++)
    {
        tmp+=strTmp[i];
        if(strs.find(tmp)!=strs.end())
        {
            int pos=strs[tmp];
            foreach (item, v) {
                if(item<strs[tmp]){
                    pos--;
                }
                else
                {
                    break;
                }
            }
            result =((result)+(pos)*entekhab[n-mj])%1000000007;
            mj++;
            v.insert(strs[tmp]);
            tmp="";
        }
    }
    cout<<result+1<<endl;
    return 0;
}

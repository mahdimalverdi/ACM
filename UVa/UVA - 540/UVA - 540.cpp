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


int students[1000000];
    list<int>::iterator laststudents[1000000];

int main()
{

    int t;
    int k=1;
    while(scanf("%i",&t)!=EOF && t!=0)
    {
    	printf("Scenario #%i\n",k++ );
        list<int> queue;
        for(int i = 0; i < t; i++)
        {
            laststudents[i+1]=queue.end();
            int n;
            scanf("%i",&n);
            repeat(n)
            {
                int x;
                scanf("%i",&x);
                students[x]=i+1;
            }
        }
        string str;
        while(cin>>str)
        {
            if(str=="STOP")
            {
                break;
            }
            else if(str=="ENQUEUE")
            {
                int x;
                scanf("%i",&x);
                auto place=laststudents[students[x]];
                if(place!=queue.end())
                {
                    place++;
                }
                queue.insert(place,x);
                laststudents[students[x]]=--place;
            }
            else
            {
                printf("%i\n",queue.front() );
                if(laststudents[students[queue.front()]]==queue.begin())
                {
                    laststudents[students[queue.front()]]=queue.end();
                }
                queue.pop_front();
            }
        }
    	printf("\n");
    }
    return 0;
}

#include <iostream>
#include <list>
using namespace std;
#define MAXN 100
#define INF 999999
int mat[MAXN][MAXN];
int flow[MAXN][MAXN];
bool visited[MAXN];
int parent[MAXN];

int n;
int s, t, c;

bool bfs()
{
    for (int i = 0; i < n; ++i)
        visited[i] = false;
    list <int> q;
    q.push_back(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();

        for (int v=0; v<n; v++)
        {
            if (visited[v]==false && flow[u][v] > 0)
            {
                q.push_back(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}

int fordFulkerson()
{
    int u, v;


    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
            flow[u][v] = mat[u][v];

    int max_flow = 0;
    while (bfs())
    {
        int path_flow = INF;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, flow[u][v]);
        }
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            flow[u][v] -= path_flow;
            flow[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
    while (true)
    {

        int countOut = 0,countIn=0;
        n=38;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = 0;
        char str[1000];

        while (cin.getline(str,1000))
        {
            if(str[0]==0)
                break;
            mat[0][str[0]-'A'+2]=str[1]-'0';
            countIn+=str[1]-'0';
            for(int i=3;str[i]!=';';i++)
            {
                mat[str[0]-'A'+2][str[i]-'0'+28]=1;
                mat[str[i]-'0'+28][1]=1;
            }
        }

        s=0;
        t=1;
        fordFulkerson();
        for (int i = 0; i < n; i++)
        {
            countOut += flow[1][i];
        }
        if(countIn==countOut)
        {
            for(int i=0;i<10;i++)
            {
                if(flow[1][i+28])
                for(int j=0;j<26;j++)
                {
                    if(flow[i+28][j+2])
                    {
                        cout<<(char)(j+'A');
                    }
                }
                else
                    cout<<"_";
            }
        }
        else
            cout<<"!";
        cout<<endl;
        if(!cin)
            break;
    }
    return 0;
}

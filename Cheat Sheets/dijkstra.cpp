#include <iostream>
#include <vector>
#include <set>
using namespace std;


const int MAXN = 20000 + 123;
const int INF = 1e9 + 123;

#define X first
#define Y second

vector<pair<int, int> > graph[MAXN];
int n, m, s, t;
vector<int> dist;

struct CMP
{
  bool operator() (int a, int b) {
    if (dist[a] == dist[b])
      return a < b;
    return dist[a] < dist[b];
  }
};

int dijkstra(int source, int target) {
  dist = vector<int>(n, INF);
  dist[source] = 0;

  set<int, CMP> unseen;
  unseen.insert(source);

  while(!unseen.empty()) {
    int v = * unseen.begin();
    unseen.erase(v);

    for (int i = 0; i < graph[v].size(); ++i)
    {
      pair<int, int> edge = graph[v][i];

      if(dist[edge.X] > dist[v] + edge.Y){
        unseen.erase(edge.X);   // <------------
        dist[edge.X] = dist[v] + edge.Y;
        unseen.insert(edge.X);    // <------------
      }
    }
  }

  return dist[target];
}

int main(int argc, char const *argv[])
{
  int T = 0;
  cin >> T;
  for (int l=1;l<=T;l++)
  {
    cin >> n >> m >> s >> t;
    for (int i = 0; i < n; ++i)
    {
      graph[i].clear();
    }
    while (m)
    {
      int a,b,w;
      cin>>a>>b>>w;
      graph[a].push_back(make_pair(b,w));
      graph[b].push_back(make_pair(a,w));
      m--;
    }
    int dis=dijkstra(s,t);
    if(dis!=INF)
    cout<<"Case #"<<l<<": "<<dis<<endl;
  else
    cout<<"Case #"<<l<<": unreachable"<<endl;
  }
  return 0;
}
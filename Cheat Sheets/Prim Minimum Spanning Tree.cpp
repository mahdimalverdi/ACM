#include <iostream>
#include <list>
using namespace std;

#define MAXN 1000
#define INF 999999

int mat[MAXN][MAXN];
int nearest[MAXN];
int dis[MAXN];

int n;
void prim(list<pair<int,int> > & eadgs)
{
	for (int i = 1; i < n; ++i)
	{
		nearest[i]=0;
		dis[i]=mat[0][i];
	}

	for (int i = 1; i < n; ++i)
	{
		int mindis=INF;
		int vnear=0;
		for(int j=1;j<n;j++)
		{
			if(dis[j]<mindis && dis[j]>0)
			{
				mindis=dis[j];
				vnear=j;
			}
		}
		eadgs.push_back(make_pair(vnear,nearest[vnear]));
		dis[vnear]=-1;
		for(int j=1;j<n;j++)
		{
			if(mat[j][vnear]<dis[j])
			{
				dis[j]=mat[j][vnear];
				nearest[j]=vnear;
			}
		}
	}
}

int main()
{
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			mat[i][j]=INF;
		}
	}
	int e;
	cin>>e;
	for (int i = 0; i < e; ++i)
	{
		int x,y,w;
		cin>>x>>y>>w;
		mat[x][y]=w;
		mat[y][x]=w;
	}
	list<pair<int,int> > eadgs;
	prim(eadgs);
	for(auto var:eadgs)
	{
		cout<<var.first<<" "<<var.second<<endl;
	}
	cin>>n;
	return 0;
}
#include <iostream>
using namespace std;
#define MAXN 100
#define INF 999999
int mat[100][100];
int flow[100][100];
bool seen[100];

int n;
int s, t, c;

int dfs(int x, int maxcount)
{
	seen[x] = true;
	for (int i = 0; i < n; i++)
	{
		if (mat[x][i] != 0 && seen[i] == false && flow[x][i] < mat[x][i])
		{
			if (t == i )
			{
				int y = min(maxcount, mat[x][i] - flow[x][i]);
				flow[x][i] += y;
				flow[i][x] -= y;
				return y;
			}
			int count = dfs(i, min(maxcount, mat[x][i] - flow[x][i]));
			if (count > 0)
			{
				flow[x][i] += count;
				flow[i][x] -= count;
				return count;
			}
		}
	}
	return 0;
}


void fordFulkerson()
{
    for (int i = 0; i < n; ++i)
		{
			seen[i] = false;
		}
		while (dfs(s, INF))
		{
			for (int i = 0; i < n; ++i)
			{
				seen[i] = false;
			}
		}
}

int main()
{
	cin >> n;
	int k = 1;
	while (n)
	{
		cin >> s >> t >> c;
		s--;
		t--;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				mat[i][j] = 0;
		while (c)
		{
			int a, b, w;
			cin >> a >> b >> w;
			a--;
			b--;
			mat[a][b] += w;
			mat[b][a] += w;
			c--;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				flow[i][j] = 0;
		for (int i = 0; i < n; ++i)
		{
			seen[i] = false;
		}
		while (dfs(s, INF))
		{
			for (int i = 0; i < n; ++i)
			{
				seen[i] = false;
			}
		}
		int count = 0;
		for (int i = 0; i < n; i++)
			count += flow[s][i];
		cout << "Network " << k << endl;
		cout << "The bandwidth is " << count << "." << endl << endl;
		cin >> n;
		k++;
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <string>
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
#define MAXN 10000

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

ii p0;

ii nextToTop(vector<ii> &S)
{
	ii p = S.back();
	S.pop_back();
	ii res = S.back();
	S.push_back(p);
	return res;
}

int swap(ii &p1, ii &p2)
{
	ii temp = p1;
	p1 = p2;
	p2 = temp;
}

int distSq(ii p1, ii p2)
{
	return (p1.X - p2.X) * (p1.X - p2.X) +
	       (p1.Y - p2.Y) * (p1.Y - p2.Y);
}

int orientation(ii p, ii q, ii r)
{
	int val = (q.Y - p.Y) * (r.X - q.X) -
	          (q.X - p.X) * (r.Y - q.Y);

	if (val == 0) return 0;  // colinear
	return (val > 0) ? 1 : 2; // clock or counterclock wise
}
int compare(const void *vp1, const void *vp2)
{
	ii *p1 = (ii *)vp1;
	ii *p2 = (ii *)vp2;
	int o = orientation(p0, *p1, *p2);
	if (o == 0)
		return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

	return (o == 2) ? -1 : 1;
}

void convexHull(std::vector<ii>  points, int n)
{
	int ymin = points[0].Y, min = 0;
	for (int i = 1; i < n; i++)
	{
		int y = points[i].Y;
		if ((y < ymin) || (ymin == y &&
		                   points[i].X < points[min].X))
			ymin = points[i].Y, min = i;
	}

	swap(points[0], points[min]);
	p0 = points[0];
	qsort(&points[1], n - 1, sizeof(ii), compare);
	int m = 1;
	for (int i = 1; i < n; i++)
	{
		while (i < n - 1 && orientation(p0, points[i],
		                                points[i + 1]) == 0)
			i++;


		points[m] = points[i];
		m++;
	}
	if (m < 3) return;

	vector<ii> S;
	S.push_back(points[0]);
	S.push_back(points[1]);
	S.push_back(points[2]);

	for (int i = 3; i < m; i++)
	{
		while (orientation(nextToTop(S), S.back(), points[i]) != 2)
			S.pop_back();
		S.push_back(points[i]);
	}
	cout << S.size() + 1 << endl;
	reverse(S.begin(), S.end());
	while (!S.empty())
	{
		ii p1 = S.back();
		cout << p1.X << " " << p1.Y << endl;
		S.pop_back();
	}
	cout << p0.X << " " << p0.Y << endl;
}

int main()
{
	int k = 0;
	scanf("%i", &k);
	printf("%i\n", k);
	repeat(k)
	{
		int n;
		scanf("%i", &n);
		std::vector<ii> v;
		loop(i, n)
		{
			int x, y;
			scanf("%i %i", &x, &y);
			v.push_back(p(x, y));
		}
		convexHull(v, n);

		if (k != 0)
		{
			scanf("%i", &n);
			printf("%i\n", n);
		}
	}
	return 0;
}

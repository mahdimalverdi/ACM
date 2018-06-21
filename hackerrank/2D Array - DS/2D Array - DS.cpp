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
using namespace std;

#define INF 99999
#define MAXN 100

#define X first
#define Y second

#define loop(x,n) for(int x = 0; x < n; ++x)
#define foreach(x,arr) for(auto x:arr)
#define repeat(x) while(x--)
#define replaceStr(str,str1,str2) while(str.find(str1)!=-1){str.replace(str.find(str1), sizeof(str2)-1, str2);}
#define eraseStr(str,str1) while(str.find(str1)!=-1){str.erase(str.find(str1), sizeof(str1)-1);}
#define p(x,y) make_pair(x,y)

int main()
{
	int maxSum=-INF;
	int mat[6][6];
	loop(i,6)
		loop(j,6)
			cin>>mat[i][j];
	loop(i,4)
		loop(j,4)
		{
			int sum=mat[i][j]+mat[i][j+1]+mat[i][j+2]+mat[i+1][j+1]+mat[i+2][j]+mat[i+2][j+1]+mat[i+2][j+2];
			maxSum=max(maxSum,sum);
		}
	cout<<maxSum<<endl;
	return 0;
}
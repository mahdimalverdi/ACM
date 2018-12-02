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
#define MAXN 1000

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

int GetCeilIndex(int arr[], int T[], int l, int r,
                 int key)
{
    while (r - l > 1)
    {
        int m = l + (r - l) / 2;
        if (arr[T[m]] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

void LongestIncreasingSubsequence(int arr[], int n)
{

    int tailIndices[MAXN];
    int prevIndices[MAXN];
    int result[MAXN];
    loop(i,n)
    {
        tailIndices[i]=0;
        prevIndices[i]=-1;
        result[i]=0;
    }

    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[tailIndices[0]])
        {
            tailIndices[0] = i;
        }
        else if (arr[i] > arr[tailIndices[len - 1]])
        {
            prevIndices[i] = tailIndices[len - 1];
            tailIndices[len++] = i;
        }
        else
        {
            int pos = GetCeilIndex(arr, tailIndices, -1,
                                   len - 1, arr[i]);

            prevIndices[i] = tailIndices[pos - 1];
            tailIndices[pos] = i;
        }
    }
    int j=0;
    printf("Max hits: %i\n", len);
    for (int i = tailIndices[len - 1]; i >= 0 && i<n; i = prevIndices[i])
        result[j++]=arr[i];
    reverse(result, result+len);
    loop (i, len)
    {
        printf("%i\n", result[i]);
    }
    printf("\n");

}
int main()
{
    int n;
    scanf("%i", &n);
    string str;
    cin.ignore();
    getline(cin, str);
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        int arr[MAXN];
        while (getline(cin, str) && str != "")
        {
            int x;
            stringstream ss(str);
            ss >> arr[j++];
        }
        LongestIncreasingSubsequence(arr, j);
    }
    return 0;
}

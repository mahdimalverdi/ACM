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


int main()
{
	string str;
	while (getline(cin, str))
	{
		int l = 0;
		stack<string> s;
		int i;
		for (i = 0; i < str.size(); i++)
		{
			string substr = "";
			if (str[i] == '(')
			{
				substr = "(";
				if (i < str.size() - 1 )
				{
					if (str[i + 1] == '*')
					{
						substr = "(*";
						i++;
					}
				}
			}
			else if (str[i] == '[')
			{
				substr = "[";
			}
			else if (str[i] == '{')
			{
				substr = "{";
			}
			else if (str[i] == '<')
			{
				substr = "<";
			}
			else if (str[i] == ')')
			{
				if (s.empty() || s.top() != "(")
				{
					break;
				}
				s.pop();
			}
			else if (str[i] == '*')
			{

				if (i < str.size() - 1 )
				{
					if (str[i + 1] == ')')
					{
						if (s.empty() || s.top() != "(*")
						{
							break;
						}
						s.pop();
						i++;
					}
				}
			}
			else if (str[i] == ']')
			{
				if (s.empty() || s.top() != "[")
				{
					break;
				}
				s.pop();
			}
			else if (str[i] == '}')
			{
				if (s.empty() || s.top() != "{")
				{
					break;
				}
				s.pop();
			}
			else if (str[i] == '>')
			{
				if (s.empty() || s.top() != "<")
				{
					break;
				}
				s.pop();
			}
			if (substr != "")
			{
				s.push(substr);
			}
			l++;
		}
			l++;
		if (s.empty() && i==str.size())
		{
			printf("YES\n");
		}
		else
		{
			printf("NO %i\n", l );
		}
	}
	return 0;
}
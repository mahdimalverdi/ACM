#include <iostream>
using namespace std;



int main()
{
int arr[1000];
	int t;
	cin>>t;
	for(int i=0;i< t;i++)
	{
		int n;
		cin>>n;
		int maxB=0;
		arr[0]=0;
		for(int j=1;j<=n;j++)
		{
			cin>>arr[j];
			maxB=max(maxB,arr[j]-arr[j-1]);
		}
		int result=maxB;
		for(int j=1;j<=n;j++)
		{
			if(maxB==arr[j]-arr[j-1])
			{
				maxB--;
			}
			else if(maxB<arr[j]-arr[j-1])
			{
				result++;
				break;
			}
		}
		cout<<"Case "<<i+1<<": "<<result<<endl;
	}
	return 0;
}
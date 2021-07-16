#include<bits/stdc++.h>
using namespace std;
int find(int a[],int start,int end)
{
	if(start>=end)return 0;
	
	int profit = 0;
	
	for(int i=start;i<end;i++)
	{
		for(int j=i+1;j<=end;j++)
		{
			if(a[j]>a[i])
			{
				int curr = a[j]-a[i] + find(a,start,i-1)+find(a,j+1,end);
				
				profit = max(profit,curr);
			}
		}
	}
	return profit;
}
int find_1(int a[],int n)
{
	int cost = 0;
	int maxi = 0;
	
	if(n==0)return 0;
	
	int mini = a[0];
	for(int i=0;i<n;i++)
	{
	   mini = min(a[i],mini);
	   
	   cost = a[i]-mini;
	   
	   maxi = max(maxi,cost);	
	}
	return maxi;
}
void find_2(int price[],int n)
{
	if(n==1)return;
	
	int i = 0;
	
	while(i<n-1)
	{
		while(i<n-1&&price[i+1]<=price[i])i++;
		
		if(i==n-1)break;
		
		int buy = i++;
		
		while(i<n-1&&price[i+1]>=price[i])i++;
		
		int sell = i++;
		
		cout<<"("<<buy<<","<<sell<<")"<<endl;
	}
}
int main()
{
	int n;
	cin >>n;
	int a[n];
	for(int i=0;i<n;i++)cin >>a[i];
	//cout<<find(a,0,n-1)<<endl;
	//cout<<find_1(a,n)<<endl;
	find_2(a,n);
}

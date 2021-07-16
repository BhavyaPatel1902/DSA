#include<bits/stdc++.h>
#define ll long long int 
//smallest subarray with sum greater than x
using namespace std;
int simple(vector <ll> a,ll n,ll x)
{
	ll mini = n+1;
	for(int i=0;i<n;i++)
	{
		ll sum = a[i];
		if(sum>x)return 1;
		for(int j=i+1;j<n;j++)
		{
			sum = sum + a[j];
			if( (sum>x) && (j-i+1)<mini)
			{
				mini = j-i+1;
			}
		}
	}
	return mini;
}
int twopointer(vector <ll> a,ll n,ll x)
{
	ll start = 0;
	ll end = 0;
	ll sum = 0;
	ll mini = n+1;
	while(end < n)
	{
		while(sum<=x&&end<n)
		{
			sum = sum + a[end];
			end++;
		}
		
		while(sum>x&&start<n)
		{
			if(end-start<mini)mini = end-start;
			
			sum = sum - a[start];
			start++;
		}
	}
	return mini;
}
int main()
{
	ll n,x;
	cin >>n>>x;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	ll ans1 = simple(a,n,x);
	ll ans2 = twopointer(a,n,x);
	cout<<ans1<<endl<<ans2;
}

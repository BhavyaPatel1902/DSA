#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll n,k;
	cin >>n>>k;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	
	int ct = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<=k)ct++;
	}
	
	int temp = 0;
	for(int i=0;i<ct;i++)
	{
		if(a[i]>k)temp++;
	}
	int ans = temp;
	int i,j;
	for(i=0,j=ct;j<n;i++,j++)
	{
		if(a[i]>k)
		{
			temp--;
		}
		if(a[j]>k)
		{
			temp++;
		}
		ans = min(ans,temp);
	}
	cout<<ans<<endl;
}

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll n,k;
	cin >>n>>k;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	sort(a.begin(),a.end());
	
	ll ans = a[n-1]-a[0];
	ll small = a[0]+k;
	ll big = a[n-1]-k;
	
	if(small>big)
	{
		ll temp = small;
		small = big;
		big = temp;
	}
	
	for(int i=1;i<n-1;i++)
	{
		ll sub = a[i]-k;
		ll add = a[i]+k;
		
		if(sub>=small||add<=big)continue;
		
		if((big-sub)<=(add-small))
		{
			small = sub;
		}
		else
		{
			big = add;
		}
	}
	cout<<min(ans,big-small);
}

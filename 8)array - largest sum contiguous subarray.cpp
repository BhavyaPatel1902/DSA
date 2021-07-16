#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll kadane_1(vector <ll> a,ll n)
{
	ll global = INT_MIN;
	ll local = 0;
	for(int i=0;i<n;i++)
	{
		local = local + a[i];
		if(local<0)local = 0;
		else if(local>global)global = local;
	}
	return global;
}
ll sum_2(vector <ll> a,ll n)
{
	ll local = a[0];
	ll global = a[0];
	for(int i=1;i<n;i++)
	{
		local = max(a[i],local+a[i]);
		global = max(local,global);
	}
	return global;
}
int main()
{
	ll n;
	cin >>n;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	ll ans1 = kadane_1(a,n);
	ll ans2 = sum_2(a,n);
	cout<<"1. "<<ans1<<endl<<"2. "<<ans2;
}

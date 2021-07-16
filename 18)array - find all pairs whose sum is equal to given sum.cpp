#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void simple(vector <ll> a,ll n,ll x)
{
	 for(int i=0;i<n;i++)
	 {
	 	for(int j=i+1;j<n;j++)
	 	{
	 	   	if(a[i]+a[j]==x)
	 	   	{
	 	   	    cout<<"1. "<<a[i]<<endl<<"2. "<<a[j]<<endl;	
			}
		}
	 }
}
void usingmap(vector <ll> a,ll n,ll sum)
{
	map <ll,ll> mp;
	for(int i=0;i<n;i++)
	{
		ll rem = sum - a[i];
		if(mp.find(rem)!=mp.end())
		{
			ll ct = mp[rem];
			for(int j=0;j<ct;j++)
			{
				cout<<"1. "<<rem<<endl<<"2. "<<a[i]<<endl;
			}
		}
		mp[a[i]]++;
	}
}
void twopointer(vector <ll> a,ll n,ll sum)
{
	ll low = 0;
	ll high = n-1;
	sort(a.begin(),a.end());
	while(low<high)
	{
		if(a[low]+a[high]==sum)
		{
			cout<<"1. "<<a[low]<<endl<<"2. "<<a[high]<<endl;
		}
		else if(a[low]+a[high]<sum)
		{
			low++;
		}
		else
		{
			high--;
		}
	}
}
int main()
{
	ll n,sum;
	cin >>n>>sum;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	simple(a,n,sum);
	usingmap(a,n,sum);
	twopointer(a,n,sum);
}

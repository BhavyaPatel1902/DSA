#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void hashing(vector <ll> a,ll n,ll k)
{
	map <ll,ll> mp;
	map <ll,ll> :: iterator it;
	for(int i=0;i<n;i++)
    {
    	mp[a[i]]++;
	}
	for(it=mp.begin();it!=mp.end();it++)
	{
		if(it->second > (n/k))
		{
			cout<<it->first<<" ";
		}
	}
}
int main()
{
	ll n,k;
	cin >>n>>k;
    vector <ll> a(n);
    
	for(int i=0;i<n;i++)cin >>a[i];
	hashing(a,n,k);
}

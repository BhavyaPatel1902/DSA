#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void simple(vector <ll> a,ll n)
{
	int ct = 0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				ct++;
			}
		}
	}
	cout<<ct<<endl;
}
void stlapproach(vector <ll> a,ll n)
{
	set <ll> s;
	set <ll> :: iterator it;
	ll ans = 0;
	s.insert(a[0]);
	for(int i=1;i<n;i++)
	{
		s.insert(a[i]);
		
		it = s.upper_bound(a[i]);
		
		ans = ans + distance(it,s.end());
	}
	cout<<ans<<endl;
}
int main()
{
	ll n;
	cin >>n;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	simple(a,n);
	stlapproach(a,n);
}

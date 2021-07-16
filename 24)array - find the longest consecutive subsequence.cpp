#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void simple(vector <ll> a,ll n)
{
	sort(a.begin(),a.end());
	ll count = 0;
	ll global = INT_MIN;
	
	vector <ll> final;
	final.push_back(a[0]);
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i-1])
		{
			final.push_back(a[i]);
		}
	}
	
	for(int i=0;i<final.size();i++)
	{
		if(i!=0&&final[i]==final[i-1]+1)
		{
			count++;
		}
		else
		{
			count = 1;
		}
		global = max(global,count);
	}
	cout<<global<<endl;
}
void hashing(vector <ll> a,ll n)
{
	set <ll> s;
	for(int i=0;i<n;i++)s.insert(a[i]);
	ll global = INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(s.find(a[i]-1)==s.end())
		{
			ll j = a[i];
			while(s.find(j)!=s.end())
			{
				j++;
			}
			global = max(global,j-a[i]);
		}
	}
	cout<<global<<endl;
}
int main()
{
	ll n;
	cin >>n;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	simple(a,n);
	hashing(a,n);
}

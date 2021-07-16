#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void simple(vector <ll> a,ll n,ll sum)
{
	for(int i=0;i<n-2;i++)
	{
		for(int j=i+1;j<n-1;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(a[i]+a[j]+a[k]==sum)
				{
					cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
					return;
				}
			}
		}
	}
	cout<<-1<<endl;
}
void twopointer(vector <ll> a,ll n,ll sum)
{
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++)
	{
		ll l = i+1;
		ll r = n-1;
		
		while(l<r)
		{
			if(a[i]+a[l]+a[r]==sum)
			{
				cout<<a[i]<<" "<<a[l]<<" "<<a[r]<<endl;
				l++;
				r--;
				return;
			}
			else if(a[i]+a[l]+a[r]<sum)
			{
				l++;
			}
			else
			{
				r--;
			}
		}
	}
	cout<<-1<<endl;
}
void hashing(vector <ll> a,ll n,ll sum)
{
	set <ll> s;
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(s.find(sum-a[i]-a[j])!=s.end())
			{
				cout<<a[i]<<" "<<a[j]<<" "<<sum-a[i]-a[j]<<endl;
				return;
			}
			s.insert(a[j]);
		}
	}
	cout<<-1<<endl;
}
int main()
{
	ll n,sum;
	cin >>n>>sum;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	simple(a,n,sum);
	twopointer(a,n,sum);
	hashing(a,n,sum);
}

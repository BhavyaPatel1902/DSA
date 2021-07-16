#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll simple(ll a[],ll b[],ll n,ll m)
{
	ll i=0,j=0,m1=-1,m2=-1;
	
	if((m+n)%2==1)
	{
		for(int k=0;k<=(n+m)/2;k++)
		{
			if(i!=n&&j!=m)
			{
				m1 = (a[i]<b[j])?a[i++]:b[j++];
			}
			else if(i<n)
			{
				m1 = a[i++];
			}
			else
			{
				m2 = b[j++];
			}
		}
		return m1;
	}
    else
    {
    	for(int k=0;k<=(n+m)/2;k++)
    	{
    		m2 = m1;
    		if(i!=n&&j!=m)
    		{
    			m1 = (a[i]<b[j])?a[i++]:b[j++];
			}
			else if(i<n)
			{
				m1 = a[i++];
			}
			else
			{
				m1 = b[j++];
			}
		}
		return (m1+m2)/2;
	}
}
int main()
{
	ll n,m;
	cin >>n>>m;
	ll a[n];
	ll b[m];
	for(int i=0;i<n;i++)cin >>a[i];
	for(int i=0;i<m;i++)cin >>b[i];
	ll ans = simple(a,b,n,m);
	cout<<ans<<endl;
}

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void simple(vector <ll> a,vector <ll> b,vector <ll> c,ll l,ll m,ll n)
{
	ll i=0,j=0;
	vector <ll> ab;
	while(i<l&&j<m)
	{
		if(a[i]<b[j])i++;
		else if(a[i]>b[j])j++;
		else
		{
			ab.push_back(a[i]);
			i++;
			j++;
		}
	}
	i = 0;
	j = 0;
	ll lm = ab.size();
	while(i<n&&j<lm)
	{
		if(c[i]<ab[j])i++;
		else if(c[i]>ab[j])j++;
		else
		{
			cout<<c[i]<<" ";
			i++;
			j++;
		}
	}
}
void threepointer(vector <ll> a,vector <ll> b,vector <ll> c,ll l,ll m,ll n)
{
    int i=0,j=0,k=0;
    while(i<l&&j<m&&k<n)
    {
    	if(a[i]==b[j]&&b[j]==c[k])
    	{
    		cout<<a[i]<<" ";
    		i++;
    		j++;
    		k++;
		}
		else if(a[i]<b[j])
		{
			i++;
		}
		else if(b[j]<c[k])
		{
			j++;
		}
		else
		{
			k++;
		}
	}
}
int main()
{
	ll l,m,n;
	cin >>l>>m>>n;
	vector <ll> a(l);
	vector <ll> b(m);
	vector <ll> c(n);
	for(int i=0;i<l;i++)cin >>a[i];
	for(int i=0;i<m;i++)cin >>b[i];
	for(int i=0;i<n;i++)cin >>c[i];
	//simple(a,b,c,l,m,n);
	threepointer(a,b,c,l,m,n);
}

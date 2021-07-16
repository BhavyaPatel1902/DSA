#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void rightrotate(vector <ll> &a,ll n,ll l,ll r)
{
	ll temp = a[r];
	for(int i=r;i>l;i--)
	{
		a[i] = a[i-1];
	}
	a[l] = temp;
}
void efficient(vector <ll> a,ll n)
{
	ll i = 0,j=n-1;
	while(i<j)
	{
		while(i<=n-1&&a[i]>0)i++;
		while(j>0&&a[j]<0)j--;
		if(i<j)
		{
			swap(a[i],a[j]);
		}
	}
	if(i==0||i==n-1)return;
	ll k = 0;
	while(k<n&&i<n)
	{
		swap(a[k],a[i]);
		i++;
		k=k+2;
	}
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	cout<<endl;
}
int main()
{
	ll n;
	cin >>n;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	efficient(a,n);
	ll outofplace = -1;
	for(int i=0;i<n;i++)
	{
		if(outofplace == -1)
		{
			if((a[i]>=0&&i%2==0)||(a[i]<=0&&i%2!=0))
			{
				outofplace = i;
			}
		}
		else
		{
			if((a[i]>=0&&a[outofplace]<0)||(a[i]<0&&a[outofplace]>=0))
			{
				rightrotate(a,n,outofplace,i);
				if(i-outofplace >= 2)
				{
					outofplace = outofplace + 2;
				}
				else
				{
					outofplace = -1;
				}
			}
		}
	}
	//for(int i=0;i<n;i++)cout<<a[i]<<" ";
	//cout<<endl;
}

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void rearrange_1(vector <ll> &a,ll start,ll end)
{
	while(start<=end)
	{
		if(a[start]<0&&a[end]<0)
		{
			start++;
		}
		else if(a[start]>0&&a[end]>0)
		{
			end--;
		}
		else if(a[start]>0&&a[end]<0)
		{
			ll temp = a[start];
			a[start] = a[end];
			a[end] = temp;
			start++;
			end--;
		}
		else
		{
			start++;
			end--;
		}
	}
}
void rearrange(vector <ll> &a,ll n)
{
	ll j=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			if(i!=j)
			{
				ll temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			j++;
		}
	}
}
int main()
{
	ll n;
	cin >>n;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	//rearrange(a,n);
	rearrange_1(a,0,n-1);
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
}

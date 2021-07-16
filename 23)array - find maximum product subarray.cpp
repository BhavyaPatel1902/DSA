#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
void simple(vector <ll> a,ll n)
{
	ll global = INT_MIN;
	for(int i=0;i<n;i++)
	{
		ll mul = a[i];
		for(int j=i+1;j<n;j++)
		{
			global = max(global,mul);
			mul = mul*a[j];
		}
		global = max(global,mul);
	}
	cout<<global<<endl;
}
void efficient(vector <ll> a,ll n)
{
	ll max_end = 1;
	ll min_end = 1;
	ll temp1 = 1;
	ll global = INT_MIN;
	int flag = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>0)
		{
			max_end = max_end*a[i];
			min_end = min(min_end*a[i],temp1);
			flag = 1;
		}
		else if(a[i]==0)
		{
			max_end = 1;
			min_end = 1;
		}
		else
		{
			ll temp = max_end;
			max_end = max(min_end*a[i],temp1);
			min_end = temp*a[i];
		}
		if(max_end>global)global = max_end;
	}
}
int main()
{
	ll n;
	cin >>n;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	simple(a,n);
	efficient(a,n);
}

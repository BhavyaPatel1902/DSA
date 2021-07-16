#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void rotate_1(vector <ll> a,ll n)
{
	ll temp = a[0];
	ll i;
	for(i=1;i<n;i++)
	{
		a[i-1]=a[i];
	}
	a[i-1]=temp;
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
}
int main()
{
	ll n;
	cin >>n;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	rotate_1(a,n);
}

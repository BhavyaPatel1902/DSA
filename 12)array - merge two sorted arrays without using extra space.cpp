#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void simple(vector <ll> &a,vector <ll> &b,ll n,ll m)
{
	for(int i=m-1;i>=0;i--)
	{
		int j;
		ll last = a[n-1];
		for(j=n-2;j>=0&&a[j]>b[i];j--)
		{
			a[j+1] = a[j];
		}
		
		if(j!=n-2||last>b[i])
		{
			a[j+1] = b[i];
			b[i] = last;
		}
	}
	cout<<"1.  ";
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	cout<<endl;
	cout<<"2.  ";
	for(int i=0;i<m;i++)cout<<b[i]<<" ";
	cout<<endl;
}
int main()
{
	ll n,m;
	cin >>n>>m;
	vector <ll> a(n);
	vector <ll> b(m);
	for(int i=0;i<n;i++)cin >>a[i];
	for(int i=0;i<m;i++)cin >>b[i];
	simple(a,b,n,m);
}

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll n,m;
	cin >>n>>m;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	if(n==0||m==0)return 0;
	if(m>n)return 0;
	ll mini = INT_MAX;
	sort(a.begin(),a.end());
	for(int i=0;i+m-1<n;i++)
	{
		ll diff = a[i+m-1]-a[i];
		mini = min(diff,mini);
	}
	cout<<mini<<endl;
}

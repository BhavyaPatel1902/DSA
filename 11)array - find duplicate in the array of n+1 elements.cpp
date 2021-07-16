#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll n;
	cin >>n;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	sort(a.begin(),a.end());
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[i+1]&&i!=n-1)
		{
			cout<<a[i]<<" ";
			flag = 1;
			break;
		}
	}
	if(flag==0)cout<<-1<<endl;
}

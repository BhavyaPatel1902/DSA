#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()                                         
{
	ll n;
	cin >>n;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	set <ll> s;
	ll sum = 0;
	int flag = 0;
	for(int i=0;i<n;i++)
	{
		sum = sum + a[i];
		if(sum==0||s.find(sum)!=s.end())
		{
			flag = 1;
			break;
		}
		s.insert(sum);
	}
	if(flag==0)cout<<"Yes";
	else cout<<"No";
}

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll n;
	cin >>n;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	ll ans = 0;
	int i=0;
	int j=n-1;
	while(i<=j)
	{
		if(a[i]==a[j])
		{
			i++;
			j--;
		}
		else if(a[i]>a[j])
		{
			j--;
			a[j] = a[j] + a[j+1];
			ans++;
		}
		else
		{
			i++;
			a[i]=a[i]+a[i-1];
			ans++;
		}
	}
	cout<<ans<<endl;
}

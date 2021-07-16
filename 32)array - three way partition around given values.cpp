#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll n,high,low;
	cin >>n>>low>>high;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	int l = 0;
	int h = n-1;
	int i = 0;
	while(i<=high)
	{
		if(a[i]<low)
		{
			swap(a[i],a[l]);
			l++;
			i++;
		}
		else if(a[i]>high)
		{
			swap(a[i],a[h]);
			i++;
			h--;
		}
		else
		{
			i++;
		}
	}
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
}

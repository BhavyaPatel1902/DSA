#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//1. Simple approach is to count 0,1,2 and fill them in the array - n
//2. Using partitioning the array.
int main()
{
	ll n;
	cin >>n;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	ll start = 0;
	ll mid = 0;
	ll end = n-1;
	while(mid<=end)
	{
		if(a[mid]<1)
		{
			ll temp = a[start];
			a[start] = a[mid];
			a[mid] = temp;
			start++;
			mid++;
		}
		else if(a[mid]>1)
		{
			ll temp = a[mid];
			a[mid] = a[end];
			a[end] = temp;
			end--;
		}
		else
		{
			mid++;
		}
	}
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
}

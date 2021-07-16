#include<bits/stdc++.h>
#define ll long long int
//1. Simple sort using merge sort and extract the element by index directly - nlogn
//2. using min heap or max heap
//3. quickselect
using namespace std;

int partition(ll a[],ll l,ll r)
{
	 ll x = a[r];
	 int i=1;
	 for(int j=l;j<=r-1;j++)
	 {
	 	if(a[j]<=x)
	 	{
	 	   swap(a[j],a[i]);
		   i++;	
		}
	 }
	 swap(a[i],a[r]);
	 return i;
}

int kthsmallest(ll a[],ll l,ll r,ll k)
{
	if(k>0&&k<=r-l+1)
	{
		int pos = partition(a,l,r);
		
		if(pos-l==k-1)return a[pos];
		else if(pos-l>k-1)return kthsmallest(a,l,pos-1,k);
		else return kthsmallest(a,pos+1,r,k-pos+l-1);
	}
	return -1;
}

int main()
{
   ll n,k;
   cin >>n>>k;
   ll a[n];
   for(int i=0;i<n;i++)cin >>a[i];
   int ans = kthsmallest(a,0,n-1,k);
   cout<<ans<<endl;
}

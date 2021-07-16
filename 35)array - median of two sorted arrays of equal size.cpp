#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void simple(ll a[],ll b[],ll n)
{
   ll i=0,j=0,m1=0,m2=0;
   
   for(int k=0;k<=n;k++)
   {	
   	  if(i==n)
   	  {
   	  	 m1 = m2;
   	  	 m2 = b[0];
   	  	 break;
	  }
	  else if(j==n)
	  {
	  	 m1 = m2;
	  	 m2 = m1;
	  	 break;
	  }
   	  if(a[i]<=b[j])
   	  {
   	  	  m1 = m2;
   	  	  m2 = a[i];
   	  	  i++;
	  }
	  else
	  {
	  	  m1 = m2;
	  	  m2 = b[j];
	  	  j++;
	  }
   }
   cout<<(m1+m2)/2<<endl; 
}
ll median(ll a[],ll n)
{
	if(n%2==0)return (a[n/2]+a[n/2-1])/2;
	else return a[n/2];
}
ll medians(ll a[],ll b[],ll n)
{
	if(n==0)return -1;
	if(n==1)return (a[0]+b[0])/2;
	if(n==2)return (max(a[0],b[0])+min(a[1],b[1]))/2;
	
	ll m1 = median(a,n);
	ll m2 = median(b,n);
	
	if(m1==m2)return m1;
	else if(m1<m2)
	{
		if(n%2==0)return medians(a+n/2-1,b,n-n/2+1);
	    else return medians(a+n/2,b,n-n/2);
	}
	else 
	{
		if(n%2==0)return medians(b+n/2-1,a,n-n/2+1);
		else return medians(b+n/2,a,n-n/2);
	}
}
int main()
{
	ll n;
	cin >>n;
	ll a[n];
	ll b[n];
	for(int i=0;i<n;i++)cin >>a[i];
	for(int i=0;i<n;i++)cin >>b[i];
	simple(a,b,n);
	ll ans = medians(a,b,n);
	cout<<ans<<endl;
}

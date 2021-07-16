#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void union_1(ll n,ll m,vector <ll> a,vector <ll> b)
{
	int i=0,j=0;
	cout<<"UNION : ";
    while(i<n&&j<m)
    {
    	if(a[i]<b[j])
    	{
    		if(i==0)cout<<a[i]<<" ";
    		else if(a[i]!=a[i-1])
    		{
    		  cout<<a[i]<<" ";
    	    }
    	    i++;
		}
		else if(a[i]>b[j])
		{
			if(j==0)cout<<b[j]<<" ";
			else if(b[j]!=b[j-1])
			{  
			  cout<<b[j]<<" ";
		    }
			j++;
		}
		else
		{
			  if(i==0||j==0)cout<<b[j]<<" ";
			  else if(a[i]!=a[i-1]&&b[j]!=b[j-1])
			  {
			     cout<<b[j]<<" ";
			  }
			  i++;
			  j++;
		}
	}
	while(i<n)
	{
		if(a[i]!=a[i-1])cout<<a[i]<<" ";
		i++;
	}
	while(j<m)
	{
		if(b[j]!=b[j-1])cout<<b[j]<<" ";
		j++;
	}
	cout<<endl;
}
void intersection(ll n,ll m,vector <ll> a,vector <ll> b)
{
	ll temp = INT_MIN;
	int i=0,j=0;
	cout<<"INTERSECTION : ";
	while(i<n&&j<m)
	{
		if(a[i]<b[j])i++;
		else if(a[i]>b[j])j++;
		else
		{
			if(temp!=a[i])
			{
			  temp = a[i];
			  cout<<temp<<" ";
		    }
			i++;
			j++;
		}
	}
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
	union_1(n,m,a,b); 
	intersection(n,m,a,b);
}

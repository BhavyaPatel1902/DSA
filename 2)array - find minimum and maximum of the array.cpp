#define ll long long int
#include<bits/stdc++.h>
//1. simple linear search - n
//2. Tournament or divide and conquer method - n
//3. pairwise comparison - n
using namespace std;
pair <ll,ll> linear(vector <ll> a,ll n)
{
	pair <ll,ll> ans;
	ll mini=INT_MAX;
	ll maxi=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(a[i]>maxi)maxi = a[i];
		if(a[i]<mini)mini = a[i];
	}
	ans.first = maxi;
	ans.second = mini;
	return ans;
}
pair <ll,ll> divide(vector <ll> a,ll start,ll end)
{
	pair <ll,ll> ans; 
	if(start==end)
	{
		ans.first = a[start];
		ans.second = a[start];
		return ans;
	}
	else if(end == start+1)
	{
		if(a[start]>a[end])
		{
			ans.first = a[start];
			ans.second = a[end];
		}
		else
		{
			ans.first = a[end];
			ans.second = a[start];
		}
		return ans;
	}
	else
	{
		ll mid = (start+end)/2;
		pair <ll,ll> t1 = divide(a,start,mid);
		pair <ll,ll> t2 = divide(a,mid+1,end);
		
		if(t1.first>t2.first)
		{
			ans.first = t1.first;
		}
		else
		{
			ans.first = t2.first;
		}
		
		if(t1.second<t2.second)
		{
			ans.second = t1.second;
		}
		else
		{
			ans.second = t2.second;
		}
		
		return ans;
	}
}
pair <ll,ll> pairwise(vector <ll> a,ll n)
{
	pair <ll,ll> ans;
	ll i;
	if(n%2==0)
	{
		if(a[0]>a[1])
		{
			ans.first = a[0];
			ans.second = a[1];
		}
		else
		{
			ans.first = a[1];
			ans.second = a[0];
		}
		i=2;
	}
	else
	{
		ans.first = a[0];
		ans.second = a[0];
		i=1;
	}
	
	while(i<n-1)
	{
		if(a[i]>a[i+1])
		{
			if(a[i]>ans.first)
			{
				ans.first = a[i];
			}
			if(a[i+1]<ans.second)
			{
				ans.second = a[i+1];
			}
		}
		else
		{
			if(a[i+1]>ans.first)
			{
				ans.first = a[i+1];
			}
			if(a[i]<ans.second)
			{
				ans.second = a[i];
			}
		}
		i=i+2;
	}
	return ans;
}
int main()
{
	ll n;
	cin >>n;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	pair <ll,ll> ans;
	//ans = linear(a,n);
	//ans = divide(a,0,n-1);
	ans = pairwise(a,n);
	cout<<"Maximum : "<<ans.first<<endl<<"Minimum : "<<ans.second<<endl;
}

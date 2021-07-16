#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void simple(vector <ll> a,ll n)
{
	ll ans = 0;
	for(int i=1;i<n-1;i++)
	{
		ll left = a[i];
		for(int j=0;j<i;j++)left = max(left,a[j]);
		ll right = a[i];
		for(int j=i+1;j<n;j++)right = max(right,a[j]);
		
		ans = ans + (min(right,left)-a[i]);
	}
	cout<<ans<<endl;
}
void twoarrays(vector <ll> a,ll n)
{
	ll left[n];
	ll right[n];
	ll ans = 0;
	left[0] = a[0];
	for(int i=1;i<n;i++)
	{
		left[i] = max(left[i-1],a[i]);
	}
	right[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--)
	{
		right[i] = max(right[i+1],a[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		ans = ans + (min(left[i],right[i])-a[i]);
	}
	cout<<ans<<endl;
}
void twopointer(vector <ll> a,ll n)
{
	ll ans=0,right_max=0,left_max=0;
	
	ll low = 0;
	ll high = n-1;
	
	while(low<=high)
	{
		if(a[low]<a[high])
		{
			if(a[low]>left_max)left_max = a[low];
			else ans = ans + (left_max-a[low]);
			low++;
		}
		else
		{
			if(a[high]>right_max)right_max = a[high];
			else ans = ans + (right_max-a[high]);
			high--;
		}
	}
	cout<<ans<<endl;
}
void prevconcept(vector <ll> a,ll n)
{
	ll prev = a[0];
	ll prev_idx = 0;
	ll ans = 0;
	ll temp = 0;
	for(int i=1;i<n;i++)
	{
		if(a[i]>=prev)
		{
			prev = a[i];
			prev_idx = i;
			temp = 0;
		}
		else
		{
			ans = ans + (prev-a[i]);
			temp = temp + (prev-a[i]);
		}
	}
	if(prev_idx<n-1)
	{
		ans = ans - temp;
		prev = a[n-1];
		for(int i=n-2;i>=prev_idx;i--)
		{
			if(a[i]>=prev)
			{
				prev = a[i];
			}
			else
			{
				ans = ans + (prev-a[i]);
			}
		}
	}
	cout<<ans<<endl;
}
int main()
{
	ll n;
	cin >>n;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	simple(a,n);
	twoarrays(a,n);
	twopointer(a,n);
	prevconcept(a,n);	
}

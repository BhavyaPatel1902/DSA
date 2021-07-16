#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll simple(vector <ll> a,ll n)
{
	if(n==1)return 0;
	ll res = INT_MAX;
	ll sub_res;
	for(int i=n-2;i>=0;i--)
	{
		if(i+a[i]>=n-1)
		{
			sub_res = simple(a,i+1);  //jumps to reach i;
			if(sub_res!=INT_MAX)
			{
				res = min(res,sub_res+1);
			}
		}
	}
	return res;
}
int basic(vector <ll> a,ll n)
{
	if(n<=1)return 0;
	if(a[0]==0)return -1;
	ll maxreach = a[0];
	ll step = a[0];
	ll jump = 1;
	
	for(int i=1;i<n;i++)
	{
		if(i==n-1)return jump;
		
		maxreach = max(maxreach,i+a[i]);
		
		step--;
		
		if(step==0)
		{
			jump++;
			
			if(i>=maxreach)return -1;
			
			step = maxreach - 1;
		}
	}
	return -1;
}
int main()
{
	ll n;
	cin >>n;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	ll ans1 = simple(a,n);
	ll ans2 = basic(a,n);
	cout<<ans1<<endl<<ans2<<endl;
}

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void rev(vector <ll> &a,ll l,ll r) 
{ 
    while (l < r) 
        swap(a[l++], a[r--]); 
}
int bsearch(vector <ll> &a,ll low,ll high,ll key)
{
	ll ans = -1;
	while(low<=high)
	{
		ll mid = low + (high-low)/2;
		if(a[mid]<=key)
		{
			high = mid-1;
		}
		else
		{
			low = mid+1;
			if(ans==-1||a[ans]>=a[mid])
			{
				ans = mid;
			}
		}
	}
	return ans;
}
bool next_permutation_1(vector <ll> &a)
{
	int len = a.size();
	int i=len-2;
	while(i>=0&&a[i]>=a[i+1])
	{
		i--;
	}
	if(i<0)return false;
	else
	{
		int pos = bsearch(a,i+1,len-1,a[i]);
		swap(a[i],a[pos]);
		rev(a,i+1,len-1);
		return true;
	}
}
void simple(vector <ll> a,ll n)
{
	//bool flag = next_permutation(a.begin(),a.end());
	bool flag = next_permutation_1(a);
	if(flag==false)sort(a.begin(),a.end());
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	cout<<endl;
}
int main()
{
	ll n;
	cin >>n;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	simple(a,n);
}

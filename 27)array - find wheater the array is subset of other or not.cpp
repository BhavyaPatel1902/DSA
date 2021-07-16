#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool simple(vector <ll> a,vector <ll> b,ll n,ll m)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]==a[j])break;
		}
		if(j==n)return 0;
	}
	return 1;
}
int search(vector <ll> a,ll low,ll high,ll x)
{
    if(high>=low)
	{
		ll mid = (high+low)/2;
		
		if((mid==0||x>a[mid-1])&&(a[mid]==x))return mid;
		else if(x>a[mid])return search(a,mid+1,high,x);
		else return search(a,low,mid-1,x);
	}
	return -1;
}
bool binarysearch(vector <ll> a,vector <ll> b,ll n,ll m)
{
	sort(a.begin(),a.end());
	for(int i=0;i<m;i++)
	{
		if(search(a,0,n-1,b[i])==-1)return false;
	}
	return true;
}
bool usingset(vector <ll> a,vector <ll> b,ll n,ll m)
{
	set <ll> s;
	for(int i=0;i<n;i++)
	{
		s.insert(a[i]);
	}
	for(int i=0;i<m;i++)
	{
		if(s.find(b[i])==s.end())return false;
	}
	return true;
}
bool usingmap(vector <ll> a,vector <ll> b,ll n,ll m)
{
	map <ll,ll> mp;
	for(int i=0;i<n;i++)
	{
		mp[a[i]]++;
	}
	for(int i=0;i<m;i++)
	{
		if(mp[b[i]]>0)
		{
			mp[b[i]]--;
		}
		else
		{
			return false;
		}
	}
	return true;
}
bool mergetype(vector <ll> a,vector <ll> b,ll n,ll m)
{
	if(n<m)return false;
	ll i=0,j=0;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	while(i<n&&j<m)
	{
		if(a[i]<b[j])
		{
			i++;
		}
		else if(a[i]==b[j])
		{
			i++;
			j++;
		}
		else if(a[i]>b[j])
		{
			return false;
		}
	}
	if(j<m)return false;
	else return true;
}
int main()
{
	ll n,m;
	cin >>n>>m;
	vector <ll> a(n);
	vector <ll> b(m);
	for(int i=0;i<n;i++)cin >>a[i];
	for(int j=0;j<m;j++)cin >>b[j];
	bool ans1 = simple(a,b,n,m);
	bool ans2 = binarysearch(a,b,n,m);
	bool ans3 = mergetype(a,b,n,m);
	bool ans4 = usingset(a,b,n,m);
	bool ans5 = usingmap(a,b,n,m);
	cout<<ans1<<endl<<ans2<<endl<<ans3<<endl<<ans4<<endl<<ans5<<endl;
}

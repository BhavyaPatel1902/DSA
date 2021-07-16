#define ll long long int
#include<bits/stdc++.h>
//naive with O(n) space to store in another array from last element.

using namespace std;
void reverse(vector <ll> a,ll start,ll end)  //n
{
	while(start<end)
	{
		ll temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		start++;
		end--;
	}
	for(int i=0;i<end;i++)cout<<a[i]<<" ";
	cout<<endl;
}
void recur_reverse(vector <ll> &a,ll start,ll end)  //n
{
	if(start>=end)return;
	
	ll temp = a[start];
	a[start] = a[end];
	a[end] = temp;
	
	recur_reverse(a,start+1,end-1);
}

int main()
{
	ll n;
	cin >>n;
	vector <ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
    reverse(a,0,n-1);
	recur_reverse(a,0,n-1);
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
}

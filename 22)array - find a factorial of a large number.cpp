#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll multiply(ll x,vector <ll> &res,ll res_size)
{
	int carry = 0;
	for(int i=0;i<res_size;i++)
	{
		ll prod = res[i]*x + carry;
		
		res[i] = prod%10;
		
		carry = prod/10;
	}
	
	while(carry)
	{
		res[res_size] = carry%10;
		carry = carry/10;
		res_size++;
	}
	
	return res_size;
}
int main()
{
	ll n;
	cin >>n;
	vector <ll> res(1000000);
	res[0]=1;
	ll res_size = 1;
	
	for(int i=2;i<=n;i++)
	{
		res_size = multiply(i,res,res_size);
	}
	
	for(int i=res_size-1;i>=0;i--)
	{
		cout<<res[i];
	}
	
	cout<<endl;
}


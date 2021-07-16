#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void simple(vector < vector <ll> > a,ll n)
{
	sort(a.begin(),a.end());
	
	stack < vector <ll> > s;
	
	vector <ll> temp(2);
	temp[0] = a[0][0];
	temp[1] = a[0][1];
	s.push(temp);

	
	for(int i=1;i<n;i++)
	{
		vector <ll> top = s.top();
		
		if(top[1] < a[i][0])
		{
			temp[0] = a[i][0];
			temp[1] = a[i][1];
			
			s.push(temp);
		}
		else if(top[1] < a[i][1])
		{
			top[1] = a[i][1];
			s.pop();
			s.push(top);
		}
	}
	
	while(!s.empty())
	{
		temp = s.top();
		cout<<temp[0]<<" "<<temp[1];
		s.pop();
	}
}
void efficient(vector < vector <ll> >a,ll n)
{
	sort(a.begin(),a.end());
	ll idx = 0;
	for(int i=1;i<n;i++)
	{
		if(a[idx][1]>=a[i][0])
		{
			a[idx][1] = max(a[idx][1],a[i][1]);
			a[idx][0] = min(a[idx][0],a[i][0]);
		}
		else
		{
			idx++;
			a[idx] = a[i];
		}
	}
	for(int i=0;i<idx+1;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	ll n;
	cin >>n;
	vector < vector <ll> > a(n,vector <ll> (2));
	ll s,e;
	for(int i=0;i<n;i++)
	{
	   for(int j=0;j<2;j++)
	   {
	   	   cin >>a[i][j];
	   }
	}
	//simple(a,n);
	efficient(a,n);
}

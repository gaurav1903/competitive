#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
	int t,n,x;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		vector<int>v;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		int req=1;
		int j=0;
		while(j<n)
		{
			if(v[j]>=req)
			{
				req++;
			}
			j++;
		}

		cout<<"Case #"<<i+1<<": "<<req-1<<endl;
	
		
		
	}
}
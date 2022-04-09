#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
	int t,r,c;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>r>>c;
		cout<<"Case #"<<i+1<<":"<<endl;
		string top="..";
		string bottom="+";
		string first=".";
		string second="|";
		for(int j=0;j<c;j++)
		{
			bottom+="-+";
			second+=".|";
			top+="+-";
			first+=".|";
		}
		top.pop_back();
		
		cout<<top<<endl;
		cout<<first<<endl;
		for(int j=0;j<r-1;j++)
		{
			cout<<bottom<<endl;
			cout<<second<<endl;

		}
		cout<<bottom<<endl;
		
	}
}

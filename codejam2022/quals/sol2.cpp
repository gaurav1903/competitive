#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
	int t,a,b,c,d;
	cin>>t;
	// fstream f;
	// f.open("out.txt",ios::out);
	for(int i=0;i<t;i++)
	{
		vector<vector<int>>v;
		for(int j=0;j<3;j++)
		{
			cin>>a>>b>>c>>d;
			v.push_back({a,b,c,d});
		}
		int maxa,maxb,maxc,maxd;
		maxa=min(min(v[0][0],v[1][0]),v[2][0]);
		maxb=min(min(v[0][1],v[1][1]),v[2][1]);
		maxc=min(min(v[0][2],v[1][2]),v[2][2]);
		maxd=min(min(v[0][3],v[1][3]),v[2][3]);
		// f<<"maxa,b,c,d "<<maxa<<" "<<maxb<<" "<<maxc<<" "<<maxd<<endl; 
		if(maxa+maxb+maxc+maxd<pow(10,6))
			cout<<"Case #"<<i+1<<": IMPOSSIBLE"<<endl;
		else
		{
			int x=0,y=0,z=0,w=0;
			int req=pow(10,6);
			if(maxa>req)
				x=req;
			else
				x=maxa;
			if(maxb+x>req)
				y=req-x;
			else
				y=maxb;
			if(x+y+maxc>req)
			{
				z=req-x-y;
			}
			else
				z=maxc;
			if(x+y+z+maxd>req)
				w=req-x-y-z;
			else
				w=maxd;
			cout<<"Case #"<<i+1<<": "<<x<<" "<<y<<" "<<z<<" "<<w<<endl;
		}
		
		
	}
}

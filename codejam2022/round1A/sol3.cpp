#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void fast()
{
    cin.tie(0)->sync_with_stdio(0); 
}
int main()
{
    fast();
    int n,t,e,w;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>e>>w;
        vector<vector<int>>data(e,vector<int>(w));
        vector<vector<vector<int>>>common(e,vector<vector<int>>(e,vector<int>(w)));
        for(int j=0;j<e;j++)
        {
            for(int k=0;k<w;k++)
            {
                cin>>data[j][k];
            }
        }
        vector<vector<int>>dp(e,vector<int>(e,INT_MAX));//dp[i][j] represents min op that are needed to do exercises from i to j and then get rid of all the weights
        //base case setup
        int sum;
        for(int j=0;j<e;j++)
        {
            //set dp[j][j]
            common[j][j]=data[j];
            sum=0;
            for(int k=0;k<w;k++)
            {
                sum+=data[j][k];
            }
            dp[j][j]=2*sum;
        }
        
        //base case set
        for(int j=1;j<e;j++)//gap between start and end of interval
        {
            for(int x=0;x+j<e;x++)//start point,,,,end point =x+j
            {
                //find common [x][x+j] by using common [x][x] & [x+1][x+j]
                sum=0;
                for(int k=0;k<w;k++)
                {
                    common[x][x+j][k]=min(common[x][x][k],common[x+1][x+j][k]);
                    sum+=min(common[x][x][k],common[x+1][x+j][k]);
                }
                for(int y=x;y<x+j;y++)//break point
                {
                    dp[x][x+j]=min(dp[x][x+j],dp[x][y]+dp[y+1][x+j]-2* sum);
                    //we need to find common between exercises
                    // dp[x][j+x]=dp[x][y]+dp[y+1][x+j]-2* (common[x][x+j])
                }
            }
        }
        cout<<"Case #"<<i+1<<": "<<dp[0][e-1]<<endl;
    }

}

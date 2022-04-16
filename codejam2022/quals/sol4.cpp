

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
//approach is to choose nodes which point directly to abyss or already done node , and now when we have chosen this node we see to its option initiators ,we choose the one which has minimum greatest node in its path to the chosen node

void dfs(int node,vector<int>&connections,vector<pair<int,int>>&dp,vector<int>&fun)
{
    int initiate=node;
    int next=connections[node];
    while(next!=-1)//if no change then return
    {
        if(max(dp[node].first,fun[node])<=dp[next].first)//should run for equal so if the node before it updates but the ans to curr node does not change still it would be better to choose initiator which increases final ans by choosing the min one , 
        {
            dp[next]={max(dp[node].first,fun[node]),initiate};
        }
        else
            return ;
        node=next;
        next=connections[node];
    }
}

int traverse(int start,vector<int>&connections,vector<int>&done,vector<int>&fun,queue<int>&endNodes,vector<vector<int>>&graph)
{
    int ans=0;
    //start is initiator initially so nobody points at it
    while(start!=-1 && done[start]==0)
    {
        for(int j=0;j<graph[start].size();j++)
        {
            if(done[graph[start][j]]==0)
            {
                endNodes.push(graph[start][j]);
            }
        }
        ans=max(ans,fun[start]);
        done[start]=1;
        start=connections[start];
    }
    return ans;
}

int main()
{
    int n,t,x;
    
    // fstream o,f;
    // f.open("input.txt",ios::in);
    // o.open("out.txt",ios::out);
    cin>>t;
    for(int i=0;i<t;i++)
    {
        
        cin>>n;
        ll sum=0;
        vector<pair<int,int>>dp(n,{INT_MAX,-1});//min of max from a route,route -initiator
        vector<int>fun;
        vector<int>done(n);
        for(int j=0;j<n;j++)
        {
            cin>>x;
            fun.push_back(x);
        }
        vector<vector<int>>graph(n);//graph[i] tells you which machines points at ith machine
        vector<int>connections;
        queue<int>endNodes;
        for(int j=0;j<n;j++)
        {
            cin>>x;
            connections.push_back(x-1);//ith pointing towards x or -1
            if(x!=0)
                graph[x-1].push_back(j);
            else
                endNodes.push(j);
        }
        //initiators will have graph[x].size()=0
        for(int j=0;j<n;j++)
        {
            if(graph[j].size()==0)//means it is a iniatiator
            {
                dp[j]={0,j};
                dfs(j,connections,dp,fun);
            }
        }
        //setting done
        // cout<<"part 1 finished"<<endl;
        // for(int j=0;j<n;j++)
        // {
        //     cout<<dp[j].first<<" "<<dp[j].second<<endl;
        // }
        // correct till here
        //now we have to start by the last layer that is poining to abyss or already done node
        while(!endNodes.empty())
        {
            int x=endNodes.front();
            
            while(done[x]==1)
            {
                endNodes.pop();
                x=endNodes.front();
            }
            
            // sum+=max(dp[x].first,fun[x]);
            int start=dp[x].second;
            // cout<<x<<"  selected "<<start<<endl;
            sum+=traverse(start,connections,done,fun,endNodes,graph);
            // cout<<endNodes.size()<<endl;
            endNodes.pop();
            //start from dp[x].second
        }
        cout<<"Case #"<<i+1<<": "<<sum<<endl;
    }
    
}

//10
// 383086787 309814115 631002069 122775430 618201149 985745883 465466895 191712715 691615844 110785617
// -1 0 1 1 1 1 1 1 1 1

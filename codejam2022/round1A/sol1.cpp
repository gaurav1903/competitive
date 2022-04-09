#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    int n,t;
    string s;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>s;
        vector<char>v(s.size());
        stack<char>st;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(st.empty())
            {
                v[i]='_';
            }
            else
            {
                if(st.top()==s[i])
                {
                    st.pop();
                    if(st.empty())
                       v[i]='_';
                    else
                        v[i]=st.top();
                }
                else
                {
                    v[i]=st.top();
                }
            }
            st.push(s[i]);
        }
        // for(auto x:v)
        //     cout<<x<<" ";
        // cout<<endl;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]<v[i] && v[i]!='_')
            {
                ans+=s[i];
                ans+=s[i];
            }
            else
                ans+=s[i];
        }
        cout<<"Case #"<<i+1<<": "<<ans<<endl;   
    }
        
}

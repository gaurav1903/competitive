#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
//max sum that we have to make 10^9*100
//2**29=5*10^8(approx)
int main()
{
    int n,t;
    fstream f;
    f.open("output.txt",ios::out);
    string s;
    cin>>t;
    for(int i=0;i<t;i++)
    {
       cin>>n;
       if(n==-1)//WA
        break;
    vector<int>last;
       ll sum=(1<<30)-1;
       for(int j=0;j<30;j++)
       {
           cout<<(1<<j)<<" ";
       }
       int maximum=pow(10,9);
       for(int j=0;j<70;j++)
       {
           sum+=maximum;
           cout<<maximum<<" ";
           maximum--;
       }
       cout<<endl;
       int x;
       for(int j=0;j<n;j++)
       {
           cin>>x;
           last.push_back(x);
           sum+=x;
       }
       ll target=sum/2;
       vector<int>ans;
       maximum=pow(10,9);
       sort(last.begin(),last.end());
       int j=last.size()-1;
       while(target>((1<<30)-1) && maximum>pow(10,9)-70)
       {
           if(target>=maximum)
           {
                ans.push_back(maximum);
                target-=maximum;
           }
           maximum--;
       }
       while(target>((1<<30)-1))
       {
           if(target>=last[j])
           {
                ans.push_back(last[j]);
                target-=last[j];
           }
           j--;
       }
       for(int j=0;j<30;j++)
       {
           if(((1<<j)&target)!=0)
            {
                ans.push_back(1<<j);
            }
       }
       for(auto x:ans)
       {
           cout<<x<<" ";
       }
       cout<<endl;
    }


}

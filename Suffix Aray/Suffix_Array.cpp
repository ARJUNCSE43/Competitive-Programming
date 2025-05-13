#include<bits/stdc++.h>
#define ll long long 
#define nline '\n'
using namespace std;

class Solution {
public:
    vector<int>buildSuffixArray(string s)
    {

       int n=s.size();
      vector<int>sa(n),rank(n),temp(n);
      for(int i=0; i<n; i++)
      {
        sa[i]=i;
        rank[i]=s[i];
      }
    
     
      for(int k=1; k<n; k<<=1)
      {
        auto cmp=[&](int i,int j)
        {
          if(rank[i]!=rank[j])return rank[i]<rank[j];
          int r1=(i+k<n)?rank[i+k]:-1;
          int r2=(j+k<n)?rank[j+k]:-1;
          return r1<r2;
        };
        sort(sa.begin(),sa.end(),cmp);
        temp[sa[0]]=0;
        for(int i=1; i<n; i++)
        {
          temp[sa[i]]=temp[sa[i-1]]+cmp(sa[i-1],sa[i]);
        }
        rank=temp;
      }
      return sa;


    }
    void solve(){
      
      
      string s;
      cin>>s;
      vector<int>ans=buildSuffixArray(s);
      for(auto &x:ans)
      {
        cout<<x<<" ";
      }


      }
  
    

};
int main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        Solution obj;
     
        obj.solve();
    }
}
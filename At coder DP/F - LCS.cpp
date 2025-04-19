#include<bits/stdc++.h>
#define vi vector<int>
#define ll long long

using namespace std;

int main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {

                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string lcs="";
        int i=n,j=m;
        while(i>0 && j>0)
        {
            if(s1[i-1]==s2[j-1])
            {
                lcs+=s1[i-1];
                i--;j--;

            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else{
                j--;
            }
        }
        reverse(lcs.begin(),lcs.end());
        cout<<lcs<<endl;
    }
}


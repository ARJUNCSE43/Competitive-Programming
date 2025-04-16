#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   int findright(vector<int>&v,int target)
   {
        int i=0,j=v.size()-1;
        int idx2=-1;
        while(i<=j)
        {
            int mid=(i+j)>>1;
            if(v[mid]==target)
            {
              idx2=mid;
              i=mid+1;
            }
            else if(v[mid]<target)
            {
                i=mid+1;
            }
            else
            {
                j=mid-1;
            }
        }
        return idx2;

   }
    int findleft(vector<int>&v,int target)
    {
        int i=0,j=v.size()-1;
        int idx1=-1,idx2=-1;
        while(i<=j)
        {
            int mid=(i+j)>>1;
            if(v[mid]==target)
            {
              idx1=mid;
              j=mid-1;
            }
            else if(v[mid]<target)
            {
                i=mid+1;
            }
            else
            {
                j=mid-1;
            }
        }
        return idx1;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
         int left=findleft(nums,target);

         int right=findright(nums,target);
         if(left>=0 && right>=0){return {left,right};}
         else return {-1,-1};

    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Solution obj;
        int n;
        cin>>n;
        vector<int>v(n);
        for(auto &x:v){cin>>x;}
        int target;
        cin>>target;
        vector<int>ans=obj.searchRange(v,target);
        cout<<ans[0]<<" "<<ans[1]<<endl;

    }
}

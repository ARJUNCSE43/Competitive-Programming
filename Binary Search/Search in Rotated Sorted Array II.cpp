#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int i=0,j=nums.size()-1;
        sort(nums.begin(),nums.end());
        while(i<=j)
        {
           int mid=(i+j)>>1;
           if(nums[mid]==target)
           {
              return true;
           }
           else if(nums[mid]<target)
           {
             i=mid+1;
           }
           else
           {
            j=mid-1;
           }
        }
        return false;

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
       cout<<obj.search(v,target)<<endl;

    }
}

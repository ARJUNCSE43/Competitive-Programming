#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

       int l=0,r=nums.size()-1;
       while(l<r)
       {
        int mid=(l+r)>>1;
        if(nums[mid]<nums[r])
        {
            r=mid;
        }
        else if(nums[mid]>nums[r])
        {
            l=mid+1;
        }
        else
        {
            r--;
        }
       }
       return nums[l];
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

       cout<<obj.findMin(v)<<endl;

    }
}

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {

       int left=0;
        int right=nums.size()-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>=nums[left])
            {
               if(nums[left]<=target && target<nums[mid])
                  right=mid-1;
                else
                   left=mid+1;
            }
            else
            {
               if(nums[mid]<target && target<=nums[right])
                 left=mid+1;
                else right=mid-1;
            }
        }
        return -1;
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

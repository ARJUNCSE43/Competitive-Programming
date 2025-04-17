#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l=0,r=nums.size();
        sort(nums.begin(),nums.end());
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(nums[mid]>mid)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;

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
       cout<<obj.missingNumber(v)<<endl;

    }
}

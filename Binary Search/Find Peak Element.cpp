#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {

       int i=0,j=nums.size()-1;
       while(i<j)
       {
          int mid=(i+j)>>1;
          if(nums[mid]>nums[mid+1])
          {
            j=mid;
          }

          else
          {
            i=mid+1;
          }
       }
       return i;

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
       cout<<obj.findPeakElement(v)<<endl;

    }
}

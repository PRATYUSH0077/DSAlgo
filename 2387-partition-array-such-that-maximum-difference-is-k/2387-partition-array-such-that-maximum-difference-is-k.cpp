class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,ans=0,n=nums.size();
        while(i<n){
            int ind= upper_bound(nums.begin()+i,nums.end(),nums[i]+k)-nums.begin();
            if(ind<n){
                i=ind;
                ans++;
            }else if(ind==n){
                i=n;
                ans++;
            }
        }
        return ans;
    }
};
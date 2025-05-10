#define ll long long
class Solution {
public:
    int fn(int n,vector<int>&nums,int target,vector<int>&dp){
        if(target==0){
            return 1;
        }
        if(dp[target]!=-1){
            return dp[target];
        }
        int ans=0;
        for(auto it:nums){
            if(it<=target){
                ans+= fn(n,nums,target-it,dp);
            }
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,1);
        // return fn(nums.size(),nums,target,dp);
        for(int i=1;i<=target;i++){
            ll ans=0;
            for(auto it:nums){
                if(it<=i){
                    ans+= dp[i-it];
                }
            }
            dp[i]=ans;
        }
        return dp[target];
    }
};
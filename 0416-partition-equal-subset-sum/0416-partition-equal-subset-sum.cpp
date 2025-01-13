class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<bool>> dp(n+1,vector<bool>(target+5,0));
        dp[n][target]=true;
        for(int i=n-1;i>=0;i--){
            for(int sum=0;sum<=target;sum++){
                bool np=dp[i+1][sum],p=false;
                if(sum+arr[i]<=target){
                    p=dp[i+1][sum+arr[i]];
                }
                dp[i][sum]= np || p;
            }
        }
        return dp[0][0];
        
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums)
            sum+=it;
        if(sum%2)
            return false;
        return isSubsetSum(nums,sum/2);
    }
};
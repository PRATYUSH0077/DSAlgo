class Solution {
public:
    int rec(int i,int j,int n,vector<int>&nums,vector<vector<int>>&dp){
        if(i>=n || j>=n){
            return 0;
        }
        
        if(dp[i][j+1]!=-1){
            return dp[i][j+1];
        }
        int LIS=0,include=0,not_include=0;
        if(j==-1 || nums[i]>nums[j]){
            include=1+rec(i+1,i,n,nums,dp);
            
        }
        not_include=rec(i+1,j,n,nums,dp);
        return dp[i][j+1]=max(include,not_include);
    }
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();
        vector<vector<int>> dp(len,vector<int>(len+1,-1));
        return rec(0,-1,len,nums,dp);
    }
};
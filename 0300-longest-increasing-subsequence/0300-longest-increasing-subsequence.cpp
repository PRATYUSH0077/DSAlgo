class Solution {
public:
    int rec(int i,int j,int n,vector<int>&nums,vector<vector<int>>&dp){
        if(i>=n || j>=n){
            return 0;
        }
        
        if(dp[i][j+1]!=-1){
            return dp[i][j+1];
        }
        int include=0,not_include=0;
        if(j==-1 || nums[i]>nums[j]){
            include=1+rec(i+1,i,n,nums,dp);
            
        }
        not_include=rec(i+1,j,n,nums,dp);
        return dp[i][j+1]=max(include,not_include);
    }
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();
        // vector<vector<int>> dp(len,vector<int>(len+1,-1));
        // return rec(0,-1,len,nums,dp);


        // bcz rec(i,j)-> mapped to dp[i][j+1] for -1 case shift
        vector<vector<int>> dp(len+1,vector<int>(len+1,0));
        for(int i=len-1;i>=0;i--){
            for(int j=-1;j<len;j++){
                int include=0,not_include=0;
                if(j==-1 || nums[i]>nums[j]){
                    include=1+dp[i+1][i+1];
                }
                // if(j>-1)
                    not_include=dp[i+1][j+1];
                dp[i][j+1]=max(include,not_include);
            }
        }
        return dp[0][0];

    }
};
class Solution {
public:
    int fn(int n,vector<int>&dp){
        if(n<0) return 0;            
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int pickone=fn(n-1,dp);
        int picktwo=fn(n-2,dp);
        return dp[n]=pickone+picktwo;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return fn(n,dp);
    }
};
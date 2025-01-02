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
        // vector<int> dp(n+1,-1);
        // return fn(n,dp);
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            int pickone=0,picktwo=0;
            pickone=dp[i-1];
            if(i>1)
                picktwo=dp[i-2];
            dp[i]=pickone+picktwo;
        }
        return dp[n];
    }
};
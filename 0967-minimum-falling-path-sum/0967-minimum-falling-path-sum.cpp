class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,1e5));
        int mini=1e6;
        for(int i=n-1;i>=0;i--){
            dp[n][i+1]=arr[n-1][i];
            mini=dp[n][i+1];
            
        }
        if(n==1)
            return mini;
        mini=1e6;
        for(int i=n-1;i>0;i--){
            for(int j=1;j<=n;j++){
                dp[i][j]=arr[i-1][j-1]+min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1]));
                if(i==1)
                    mini=min(mini,dp[i][j]);
            }
        }
        return  mini;
    }
};
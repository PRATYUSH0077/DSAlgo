class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),sum=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--){
            sum+=grid[i][n-1];
            dp[i][n-1]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=grid[m-1][i];
            dp[m-1][i]=sum;
        }
        
        // dp[m-1][n-1]=grid[m-1][n-1];
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};
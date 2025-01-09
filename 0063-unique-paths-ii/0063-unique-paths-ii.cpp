class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m=arr.size(),n=arr[0].size();
        vector<vector<long long>> dp(m,vector<long long>(n,0));
        for(int i=n-1;i>=0;i--){
            if(!arr[m-1][i])
                dp[m-1][i]=1;
            else
                break;
        }
        for(int i=m-1;i>=0;i--){
            if(!arr[i][n-1])
                dp[i][n-1]=1;
            else
                break;
        }
        if(arr[0][0] ||arr[m-1][n-1])
            return 0;
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(!arr[i+1][j])
                    dp[i][j]+= dp[i+1][j];
                if(!arr[i][j+1])
                    dp[i][j]+= dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};
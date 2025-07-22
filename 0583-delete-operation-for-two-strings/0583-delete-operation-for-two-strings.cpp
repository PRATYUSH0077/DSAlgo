class Solution {
public:
    int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans=0;
                if(s1[i]==s2[j]){
                    ans=1+dp[i+1][j+1];
                }else{
                    ans=max(dp[i][j+1],dp[i+1][j]);
                }
                dp[i][j]=ans;
            }
        }
        return (m+n-2*dp[0][0]);
    }
};
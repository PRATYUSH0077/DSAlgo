class Solution {
public:
    int lcs(int i,int j,int n,int m,string &s1,string &s2,vector<vector<int>>&dp){
        if(j==m){
            return 1;
        }
        if(i==n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s1[i]==s2[j]){
            ans+=lcs(i+1,j+1,n,m,s1,s2,dp);
        }
        ans+=lcs(i+1,j,n,m,s1,s2,dp);
        
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // int ans=lcs(0,0,n,m,s,t,dp);
        // return ans;

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][m]=1;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                long long int ans=0;
                if(s[i]==t[j]){
                    ans+= 1LL*dp[i+1][j+1];
                }
                ans+= 1LL*dp[i+1][j];
                dp[i][j]=(int)ans;
            }
        }

        return dp[0][0];
    }
};
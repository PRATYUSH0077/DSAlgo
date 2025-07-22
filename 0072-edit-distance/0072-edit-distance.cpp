class Solution {
public:
    int lcs(int i,int j,int n,int m,string& s, string& t,vector<vector<int>>&dp){
        if(i==n && j==m){
            return 0;
        }else if(i==n && j<m){
            return m-j;
        }else if(j==m && i<n){
            return n-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=INT_MAX;
        if(s[i]==t[j]){
            ans= lcs(i+1,j+1,n,m,s,t,dp);
        }else{
            ans=min(ans,1+lcs(i+1,j,n,m,s,t,dp)); // delete fro first word
            ans=min(ans,1+lcs(i+1,j+1,n,m,s,t,dp)); // replace both the words to same leeter
            ans=min(ans,1+lcs(i,j+1,n,m,s,t,dp));  // delete from second word
        }
        return dp[i][j]=ans;
    }
    int minDistance(string s, string t) {
        int n=s.size(),m=t.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // int ans= lcs(0,0,n,m,s,t,dp);
        // return ans;

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++){
            dp[n][j]=m-j;
        }
        for(int i=0;i<=n;i++){
            dp[i][m]=n-i;
        }
        dp[n][m]=0;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans=INT_MAX;
                if(s[i]==t[j]){
                    ans=dp[i+1][j+1];
                }else{
                    ans=min(ans,1+dp[i+1][j]);
                    ans=min(ans,1+dp[i+1][j+1]);
                    ans=min(ans,1+dp[i][j+1]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];


        return 0;
    }
};
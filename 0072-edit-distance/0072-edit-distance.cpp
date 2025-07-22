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
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans= lcs(0,0,n,m,s,t,dp);
        return ans;
        return 0;
    }
};
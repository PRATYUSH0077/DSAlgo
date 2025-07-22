class Solution {
public:
    int lcs(int i,int j,int n,string &s1,string &s2,vector<vector<int>>&dp){
        if(i==n || j==n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s1[i]==s2[j]){
            ans=1+lcs(i+1,j+1,n,s1,s2,dp);
        }else{
            ans=max(lcs(i+1,j,n,s1,s2,dp),lcs(i,j+1,n,s1,s2,dp));
        }
        return dp[i][j]=ans;
    }
    int minInsertions(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=lcs(0,0,n,s,s2,dp);
        return (n-ans);
    }
};
class Solution {
public:
    bool rec(int i,int j,int n,int m,string &s,string &p,vector<vector<int>>& dp){

        if(i==n){
            if(j==m) return true;
            else if(p[j]=='*'){
                while(j<m){
                    if(p[j]!='*') return false;
                    j++;
                }
                return true;
            }
            return false;
        }
        else if(j==m && i<n) return false;


        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool ans=false;
        if(p[j]=='?' || s[i]==p[j]){
            ans|= rec(i+1,j+1,n,m,s,p,dp);
        }else if(p[j]=='*'){
            ans|= rec(i+1,j+1,n,m,s,p,dp);
            ans|= rec(i+1,j,n,m,s,p,dp);
            ans|= rec(i,j+1,n,m,s,p,dp);
        }
        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(0,0,n,m,s,p,dp);
    }
};
class Solution {
public:
    int fn(int i,int sum,string &s,int size,vector<vector<int>> &dp){
        if(i<0){
            return 0;
        }
        if(dp[i][size]!=-1){
            return dp[i][size];
        }
        int np=0,p=0;
        np=fn(i-1,sum,s,size,dp);
        if(sum >= (s[i]-'0')*pow(2,size) ){
            p=1+fn(i-1,sum-((s[i]-'0')*pow(2,size)),s,size+1,dp);
        }
        return dp[i][size]=max(np,p);
    }
    int longestSubsequence(string s, int k) {
        // vector<vector<int>> dp(s.size(),vector<int>(k+1,-1));
        vector<vector<int>> dp(s.size(),vector<int>(s.size()+1,-1));
        return fn(s.size()-1,k,s,0,dp);
    }
};
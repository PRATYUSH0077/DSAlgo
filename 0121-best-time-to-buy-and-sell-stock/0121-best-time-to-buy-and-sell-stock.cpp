class Solution {
public:
    int rec(int i,int n,bool canBuy,vector<int>& prices,vector<vector<int>> &dp){
        if(i==n){
            return 0;
        }
        if(dp[i][canBuy]!=-1){
            return dp[i][canBuy];
        }
        int ans=0;
        if(canBuy){
            int buy= rec(i+1,n,false,prices,dp)-prices[i];
            int notbuy=rec(i+1,n,true,prices,dp);
            ans= max(buy,notbuy);
        }else{
            int sell=prices[i];
            int notsell=rec(i+1,n,canBuy,prices,dp);
            ans= max(sell,notsell);
        }
        return dp[i][canBuy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return rec(0,n,true,prices,dp);
    }
};
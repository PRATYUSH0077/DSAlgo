class Solution {
public:
    int fn(int i,int n,int fee,bool canBuy,vector<int>&prices,vector<vector<int>>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][canBuy]!=-1){
            return dp[i][canBuy];
        }
        int ans=0;
        if(canBuy){
            int buy=fn(i+1,n,fee,false,prices,dp)-prices[i];
            int nbuy=fn(i+1,n,fee,canBuy,prices,dp);
            ans=max(buy,nbuy);
        }else{
            int sell=fn(i+1,n,fee,true,prices,dp)+(prices[i]-fee);
            int nsell=fn(i+1,n,fee,canBuy,prices,dp);
            ans=max(sell,nsell);

        }
        return dp[i][canBuy]=ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
         int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        return fn(0,n,fee,true,prices,dp);
    }
};
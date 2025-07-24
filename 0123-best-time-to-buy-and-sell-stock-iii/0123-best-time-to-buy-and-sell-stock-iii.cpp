class Solution {
public:
    int rec(int i,int n,bool canBuy,int cnt,vector<int>& prices,vector<vector<vector<int>>> &dp){
        if(i==n || cnt>=2){
            return 0;
        }
        if(dp[i][canBuy][cnt]!=-1){
            return dp[i][canBuy][cnt];
        }
        int ans=0;
        if(canBuy ){
            int buy= rec(i+1,n,false,cnt,prices,dp)-prices[i];
            int notbuy=rec(i+1,n,canBuy,cnt,prices,dp);
            ans= max(buy,notbuy);
        }else{
            int sell=rec(i+1,n,true,cnt+1,prices,dp)+prices[i];
            int notsell=rec(i+1,n,canBuy,cnt,prices,dp);
            ans= max(sell,notsell);
        }
        return dp[i][canBuy][cnt]=ans;
        return ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(3,-1)));
        return rec(0,n,true,0,prices,dp);
    }
};
class Solution {
public:
    int rec(int i,int k,int n,bool canBuy,int cnt,vector<int>& prices,vector<vector<vector<int>>> &dp){
        if(i==n || cnt>=k){
            return 0;
        }
        if(dp[i][canBuy][cnt]!=-1){
            return dp[i][canBuy][cnt];
        }
        int ans=0;
        if(canBuy){
            int buy= rec(i+1,k,n,false,cnt,prices,dp)-prices[i];
            int notbuy=rec(i+1,k,n,canBuy,cnt,prices,dp);
            ans= max(buy,notbuy);
        }else{
            int sell=rec(i+1,k,n,true,cnt+1,prices,dp)+prices[i];
            int notsell=rec(i+1,k,n,canBuy,cnt,prices,dp);
            ans= max(sell,notsell);
        }
        return dp[i][canBuy][cnt]=ans;
        return ans;
    }
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(k+1,-1)));
        return rec(0,k,n,true,0,prices,dp);
    }
};
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<long long>> pre(m,vector<long long>(n));
        pre[0][0]=grid[0][0],pre[1][0]=grid[1][0];
        for(int i=1;i<n;i++){
            pre[0][i]=pre[0][i-1]+grid[0][i];
            pre[1][i]=pre[1][i-1]+grid[1][i];
        }
        long long sum1=pre[0][n-1],ans=1e10,temp,temp2;
        for(int i=0;i<n;i++){
            temp=sum1-pre[0][i],temp2=0;
            if(i>0)
                temp2= pre[1][i-1];
            ans=min(ans,max(temp,temp2));
        }
        return ans;

    }
};
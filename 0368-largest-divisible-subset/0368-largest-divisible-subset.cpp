class Solution {
public:
    int rec(int i,int j,int n,vector<int> &nums,vector<vector<int>>&dp){
        if(i>=n) return 0;
        if(dp[i][j+1]!=-1) return dp[i][j+1];

        int np=0,p=0;
        np=rec(i+1,j,n,nums,dp);
        if(j==-1 || nums[i]%nums[j]==0){
            p=1+rec(i+1,i,n,nums,dp);
        }
        return dp[i][j+1]=max(np,p);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        cout<< rec(0,-1,n,nums,dp)<<endl;
        vector<int> ans;
        // for(auto it:dp){
        //     for(auto it2:it){
        //         cout<<it2<<" ";
        //     }
        //     cout<<endl;
        // }
        int i=0,j=-1;
        while(i<n){
            cout<<i<<" "<<j<<endl;
            int np=dp[i+1][j+1],p=dp[i+1][i+1];
            if(p>=np && (j==-1 || nums[i]%nums[j]==0)){
                ans.push_back(nums[i]);                
                j=i;
            }
            i++;
        }
        return ans;
    }
};
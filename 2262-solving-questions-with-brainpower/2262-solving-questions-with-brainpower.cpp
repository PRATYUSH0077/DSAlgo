class Solution {
public:
    long long fn(int ind,vector<vector<int>>& questions,vector<long long > &dp)
    {
        if(ind>=questions.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        long long take = questions[ind][0]+ fn(ind+questions[ind][1]+1,questions,dp);
        long long nottake=fn(ind+1,questions,dp);
        return dp[ind]=max(nottake,take);
    }


    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size()+1,-1);
        // return questions.size();
        // long long ans= fn(0,n,questions,dp);
        return fn(0,questions,dp);
    }
};
class Solution {
public:
    int fn(int i,int k ,int prev,vector<vector<int>>& events,vector<vector<int>>& dp ){
        if(k==0 || i>=events.size()) return 0;

        if(dp[i][k]!=-1) return dp[i][k];

        int not_attend=fn(i+1,k,prev,events,dp);

        int pos;
        for(pos=i+1;pos<events.size();pos++){
            if(events[pos][0]>events[i][1]) 
                break;
        }
        int  attend= events[i][2] + fn(pos,k-1,events[i][1],events,dp);
    
        return dp[i][k]=max(not_attend,attend);
    }


    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<vector<int>> dp(events.size()+1,vector<int>(k+1,-1));
        int ans= fn(0,k,0,events,dp);
        return ans;
    }
};
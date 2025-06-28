#define pii pair<int,int>
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        set<int> s;
        while(!pq.empty()){
            s.insert(pq.top().second);
            pq.pop();
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(s.find(i)!=s.end()){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
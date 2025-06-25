class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        if (x == 0) return 0; 
        set<int> st;
        int ans = INT_MAX;
        int n = nums.size();
        
        for (int r = x; r < n; ++r) {
            st.insert(nums[r - x]);

            auto it = st.lower_bound(nums[r]);
            if (it != st.end()) {
                ans = min(ans, abs(*it - nums[r]));
            }

            if (it != st.begin()) {
                --it;
                ans = min(ans, abs(*it - nums[r]));
            }
        }
        return ans;
    }
};
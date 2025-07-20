class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0,odd=0;
        for(auto &it:nums){
            it=it%2;
            if(it) odd++;
            else even++;
        }
        int ans=max(even,odd),cnt=1,n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                continue;
            }else{
                cnt++;
            }
        }
        return max(ans,cnt);
    }

};
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        set<int> s;
        for(auto it:nums){
            s.insert(it);
        }
        int comp=s.size(),ans=0;
        for(int i=0;i<n;i++){
            set<int> s1;
            for(int j=i;j<n;j++){
                s1.insert(nums[j]);
                if(s1.size()==comp){
                    ans++;
                }else if(s1.size()>comp){
                    break;
                }
            }
        }
        return ans;
    }
};
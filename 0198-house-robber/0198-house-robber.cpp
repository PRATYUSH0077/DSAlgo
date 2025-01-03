class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> cash(n,0);
        cash[n-1]=nums[n-1];
        for(int i=n-1;i>=0;i--){
            int pick=nums[i],notpick=0;
            if(i+1<n){
                notpick=cash[i+1];
            }
            if(i+2 <n){
                pick+= cash[i+2];
            }
            cash[i]=max(pick,notpick);
        }
        return cash[0];
    }
};
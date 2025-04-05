class Solution {
public:
    int ans=0;
    void fn(int i,int xo,vector<int>& nums){
        if(i==nums.size()){
            return;
        }
        fn(i+1,xo,nums);
        
        ans+= (xo^nums[i]);
        fn(i+1,xo^nums[i],nums);
    }
    int subsetXORSum(vector<int>& nums) {
        fn(0,0,nums);
        return ans;
    }
};
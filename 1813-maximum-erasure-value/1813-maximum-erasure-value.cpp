class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size(),i=0,j=0,sum=0,ans=0;
        set<int> s;
        while(j<n){
            if( s.find(nums[j])!=s.end()  ){
                while(s.find(nums[j])!=s.end()){
                    s.erase(nums[i]);
                    sum-=nums[i];
                    i++;
                }
            }else{
                sum+= nums[j];
                s.insert(nums[j]);
                ans=max(ans,sum);
                j++;
            }
        }
        return ans;
    }
};
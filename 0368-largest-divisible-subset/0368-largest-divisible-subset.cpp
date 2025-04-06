class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> max_ele(n,1),index(n,-1);
        int maxi=1,max_index=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0 && max_ele[i]+1>max_ele[j]){
                    index[j]=i;
                    max_ele[j]=max_ele[i]+1;
                    if(max_ele[j]>maxi){
                        maxi=max_ele[j];
                        max_index=j;
                    }
                }
            }
        }
        vector<int> ans;
        while(max_index>=0){
            ans.push_back(nums[max_index]);
            max_index=index[max_index];
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int n=nums.size(),cnt=1;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(cnt%3==0){
                ans.push_back(temp);
                temp.clear();
            }else if(nums[i]-temp[0]>k){
                return {};
            }
            temp.push_back(nums[i]);
            cnt++;
        }
        if(cnt%3==0){
            ans.push_back(temp);
        }
        return ans;
    }
};
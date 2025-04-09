class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       set<int> s;
       for(auto it:nums) {
        if(it<k){
            return -1;
        }
        s.insert(it);
       }
       if(s.find(k)!=s.end()){
        return s.size()-1;
       }
       return s.size();
    }
};
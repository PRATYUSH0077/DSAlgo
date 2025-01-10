class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26,0);
        int n=words1.size(),m=words2.size();
        for(auto it:words2){
            vector<int> curr_cnt(26,0);
            for(auto it2:it){
                curr_cnt[it2-'a']++;
            }
            for(int i=0;i<26;i++){
                freq[i] = max(curr_cnt[i],freq[i]);
            }
        }
        vector<string> ans;
        for(auto it:words1){
            vector<int> curr_cnt(26,0);
            for(auto it2:it){
                curr_cnt[it2-'a']++;
            }
            bool canInclude=true;
            for(int i=0;i<26;i++){
                if(curr_cnt[i]<freq[i]){
                    canInclude=false;
                    break;
                }
            }
            if(canInclude)
                ans.push_back(it);
        }
        return ans;
    }
};
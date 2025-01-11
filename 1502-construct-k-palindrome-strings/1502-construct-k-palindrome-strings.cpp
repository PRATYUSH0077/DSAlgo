class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> freq(26,0);
        for(auto it:s){
            freq[it-'a']++;
        }
        int cnt=0;
        for(auto it:freq){
            if(it%2){
                cnt++;
            }
        }
        return cnt<=k && s.size()>=k;
    }
};
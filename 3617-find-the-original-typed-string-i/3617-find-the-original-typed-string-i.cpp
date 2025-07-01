class Solution {
public:
    int possibleStringCount(string s) {
        int n=s.size();
        int cnt=1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                cnt++;
            }
        }
        return cnt;
    }
};
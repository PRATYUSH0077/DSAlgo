class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size(),m=shifts.size();
        vector<int> shift(n+1,0);
        for(auto it:shifts){
            shift[it[0]]+= ((it[2]==1) ? 1:-1);
            shift[it[1]+1]-= ((it[2]==1) ? 1:-1);
        }
        int curr=0;
        for(int i=0;i<n;i++){
            curr+= shift[i];
            shift[i]=curr;
        }

        for(int i = 0; i < n; ++i) {
            int netShift = (shift[i] % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + netShift) % 26;
        }

        return s;
    }
};
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.size();
        vector<long long> shift(n,0);
        shift[n-1]=shifts[n-1];
        for(int i=n-2;i>=0;i--){
            shift[i]=shift[i+1]+shifts[i];
        }
        for(int i = 0; i < n; ++i) {
            int netShift = (shift[i] % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + netShift) % 26;
        }
        return s;
    }
};
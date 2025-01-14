class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> freq1(n+1,0),freq2(n+1,0),ans(n);
        for(int i=0;i<n;i++){
            int cnt=0;
            freq1[A[i]]++;
            freq2[B[i]]++;
            for(int j=1;j<=n;j++){
                cnt+= min(freq1[j],freq2[j]);
            }
            ans[i]=cnt;
        }
        return ans;
    }
};
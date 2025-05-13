class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int ans=0,M=1e9+7;
        vector<int> freq(26,0);
        for(auto it:s){
            freq[it-'a']++;
        }
        for(int i=1;i<=t;i++){
            int temp_a=0,temp_b=0;
            if(freq[25]>0){
                temp_a=freq[25];
                temp_b=freq[25];
                freq[25]=0;
            }
            for(int j=24;j>=0;j--){
                if(freq[j]>0){
                    freq[j+1]= (freq[j+1]%M + freq[j]%M)%M;
                    freq[j]=0;
                }
            }
            freq[0]= (freq[0]%M+temp_a%M)%M;
            freq[1]= (freq[1]%M+temp_b%M)%M;
        }
        for(int i=0;i<26;i++){
            ans= (ans%M + freq[i]%M)%M;
        }
        return ans;
    }
};
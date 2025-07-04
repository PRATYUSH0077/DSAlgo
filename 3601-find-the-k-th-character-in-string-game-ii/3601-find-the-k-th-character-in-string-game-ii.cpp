class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        // vector<pair<int,int>> vec;
        vector<int> vec;
        long long temp=k;
        while(temp!=1){
            int temp2=log2(temp-1);
            long long temp3=pow(2,temp2);
            temp-=temp3;
            vec.push_back(temp2+1);
        }
        reverse(vec.begin(),vec.end());
        char ans='a';
        for(auto it:vec){
            int temp1=operations[it-1];
            if(temp1==1){
                ans='a' + (ans-'a'+1)%26;
            }
        }
        return ans;

    }
};
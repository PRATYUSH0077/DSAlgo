class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        // vector<int> canBe(n,-1);
        // canBe[0]=0;
        int initial=0,prev=0,curr;
        for(int i=0;i<n-1;i++){
            curr= prev^derived[i];
            prev=curr;
        }
        if(curr^initial==derived[n-1])
            return true;
        return false;
    }
};
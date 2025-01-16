class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int xor1=0,xor2=0;
        for(auto it:nums1){
            xor1^=it;
        }
        for(auto it:nums2){
            xor2^=it;
        }
        if(n1%2==0 && n2%2==0){
            return 0;
        }else if(n2%2==0){
            return xor2;
        }else if(n1%2==0){
            return xor1;
        }
        return xor1^xor2;
    }
};
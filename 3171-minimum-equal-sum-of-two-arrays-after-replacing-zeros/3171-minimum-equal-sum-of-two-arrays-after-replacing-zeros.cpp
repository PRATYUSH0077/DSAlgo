class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0,sum2=0,zero1=0,zero2=0;

        for(auto it:nums1){
            sum1+= it;
            zero1+= (it==0);
        }
        for(auto it:nums2){
            sum2+=it;
            zero2+= (it==0);
        }

        if((zero1==0 && sum2+zero2>sum1 )
            || (zero2==0 && sum1+zero1>sum2)
            || (zero1==0 && zero2==0 && sum1!=sum2)
        ){
            return -1;
        }
        return max(sum1+zero1,sum2+zero2);
    }
};
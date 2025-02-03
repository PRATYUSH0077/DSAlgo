class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            bool isBig=true,isSmall=true;
            int prev=nums[i];
            for(int j=i+1;j<=n;j++){
                if(j==n){
                    ans=max(ans,j-i);
                }
                else if(isBig && nums[j]>prev){
                    // cout<<i<<" "<<j<<endl;
                    isBig=true;
                    isSmall=false;
                }else if(isSmall && nums[j]<prev){
                    isSmall=true;
                    isBig=false;
                }else{
                    ans=max(ans,j-i);
                    break;
                }
                prev=nums[j];
            }
        }
        return ans;
    }
};
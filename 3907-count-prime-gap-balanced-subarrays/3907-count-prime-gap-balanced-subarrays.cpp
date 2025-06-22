class Solution {
public:
    vector<bool> Prime;
    const int MAX=5e4;
    Solution():Prime(1e5,1){
        sieve();
    }
    void sieve(){
        Prime[0]=Prime[1]=0;
        for(int i=2;i<=MAX;i++){
            if(Prime[i]){
                for(int j=2*i ;j<=MAX;j+=i){
                    Prime[j]=0;
                }
            }
        }
    }
    int primeSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0,ans=0,prev=-1,curr=-1;
        multiset<int> ms;
        while(r<n){
            if(Prime[nums[r]]){
                prev=curr;
                curr=r;
                ms.insert(nums[r]);
            }

            while(ms.size()>0 && *ms.rbegin()-*ms.begin()>k){
                if(Prime[nums[l]]){
                    ms.erase(ms.find(nums[l]));
                }
                l++;
            }


            if(ms.size()>1){
                ans+= (prev-l+1);
            }
            r++;
        }
        return ans;
    }
};
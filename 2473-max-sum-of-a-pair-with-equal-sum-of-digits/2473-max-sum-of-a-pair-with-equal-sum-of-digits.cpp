#define pqi priority_queue<int,vector<int>,greater<int>>
class Solution {
public:
    int sum(int n){
        int ans=0;
        while(n>0){
            ans+= n%10;
            n/=10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,pqi> mp;
        for(auto it:nums){
            int temp=sum(it);
            pqi *q= &mp[temp];
            (*q).push(it);
            // cout<<it<<" "<<temp<<" "<<(*q).size()<<endl;
            if((*q).size()>2){
                (*q).pop();
            }
        }
        int maxi=-1;
        for(auto it:mp){
            // cout<<it.second.size()<<endl;
            if(it.second.size()==2){
                int temp1=it.second.top();
                it.second.pop();
                int temp2=it.second.top();
                it.second.pop();
                maxi=max(maxi,temp1+temp2);
            }
        }
        return maxi;
    }
};
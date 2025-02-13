#define ll long long int
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(auto it:nums){
            if(it<k)
                pq.push(it);
        }
        int ans=0;
        while(pq.size()>=2){
            ans++;
            ll temp1=pq.top();
            pq.pop();
            ll temp2=pq.top();
            pq.pop();
            ll temp3 =2*min(temp1,temp2)+max(temp1,temp2);
            if(temp3<k)
                pq.push(temp3);
        }
        if(pq.size()==1)
            ans++;
        return ans;
    }
};
class Solution {
public:
    int maxEvents(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=0,maxi=0;
        for(int i=0;i<n;i++){
           maxi=max(maxi,arr[i][1]);        
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        int j=0;
        for(int i=1;i<=maxi;i++){
            while(j<n && arr[j][0]==i){
                pq.push(arr[j][1]);  
                j++;              
            }
            while(!pq.empty() && pq.top()<i){
                pq.pop();
            }
            if(!pq.empty()){
                ans++;
                pq.pop();
            }
            if(j==n && pq.empty()){
                break;
            }
        }

        return ans;
    }
};
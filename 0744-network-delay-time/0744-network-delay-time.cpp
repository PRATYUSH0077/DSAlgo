class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        // dist[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            int distance= pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int edgeweight=it.second;
                int adjNode=it.first;
                if(edgeweight+distance < dist[adjNode]){
                    dist[adjNode]=edgeweight+distance;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        int maxi=-1;
        for(auto i=1;i<=n;i++){
            if(dist[i]>maxi) maxi=dist[i];
            if(dist[i]==INT_MAX) return -1;
        }
        // if(n==5) return dist[1];
        return maxi;
    }
};
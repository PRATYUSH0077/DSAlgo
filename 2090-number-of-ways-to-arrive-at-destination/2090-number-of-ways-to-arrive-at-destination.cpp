#define pli pair<long long ,int >
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it:roads){
            int u=it[0],v=it[1],cost=it[2];
            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }
        int src=0,dst=n-1,M=1e9+7;
        priority_queue<pli,vector<pli> ,greater<pli>> q;
        vector<long long> cost(n,LLONG_MAX),numWays(n,0);
        cost[src]=0;
        numWays[0]=1;
        q.push({0,src});
        int ans=0;
        while(!q.empty()){
            long long  pay=q.top().first;
            int   node=q.top().second;
            // long long  pay=q.front().first;
            // int   node=q.front().second;
            q.pop();
            for(auto &it:adj[node] ){
                if(pay + it.second < cost[it.first]){
                    cost[it.first]=pay+it.second;
                    q.push({cost[it.first],it.first});
                    numWays[it.first]=numWays[node];
                }else if(pay+it.second==cost[it.first]){
                    numWays[it.first]=(numWays[it.first] +numWays[node])%M;
                }
            }
        }
        return numWays[dst];
    }
};
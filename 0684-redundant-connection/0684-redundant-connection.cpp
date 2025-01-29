class Solution {
public:
    bool isCycle(int i,vector<vector<int>>&adj){
        queue<int> q;
        int n=adj.size();
        vector<int> visited(n,0);
        q.push(i);
        while(!q.empty()){
            int node=q.front();
            if(visited[node]){
                return true;
            }
            visited[node]=1;
            q.pop();
            for(auto it:adj[node]){
                if(!visited[it]){
                    q.push(it);
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            if(isCycle(it[0],adj))
                return it;
            
        }

        return {};
    }
};
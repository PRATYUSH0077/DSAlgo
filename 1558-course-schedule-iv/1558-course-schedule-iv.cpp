class Solution {
public:
    void bfs(int i,int n,vector<vector<int>>&adj,vector<vector<int>>&vec){
        vector<int> visited(n,0);
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push(it);
                    vec[i][it]=1;
                }
            }
        }
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> vec(n,vector<int>(n)),adj(n);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0;i<n;i++){
            bfs(i,n,adj,vec);
        }
        vector<bool> ans;
        for(auto it:queries){
            if(vec[it[0]][it[1]]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
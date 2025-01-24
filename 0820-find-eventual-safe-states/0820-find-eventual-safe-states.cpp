class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         vector<vector<int>> adjlist(graph.size());
        vector<int> indegree(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(auto it:graph[i]){
                adjlist[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0 ; i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto neighbour: adjlist[node]){
                if(--indegree[neighbour]==0) 
                    q.push(neighbour);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
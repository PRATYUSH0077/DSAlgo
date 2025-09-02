class Solution {
public:
   int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<int>adj[n+1];
    vector<int>indegree(n+1,0);
    for(auto & e:relations){
      adj[e[0]].push_back(e[1]);
      indegree[e[1]]++;
    }
    queue<int>q;
    vector<int>finish_time(n+1,0);
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
            finish_time[i]=time[i-1];
        }
    }
    int ans=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        ans=max(ans,finish_time[u]);
        for(int v:adj[u])
        {
            finish_time[v]=max(finish_time[v],finish_time[u]+time[v-1]);
            indegree[v]--;
            if(indegree[v]==0)
            {
                q.push(v);
            }   
        }
    }
    return ans;
        
    }
};

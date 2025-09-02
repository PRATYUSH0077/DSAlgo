class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    for (auto& r : relations) {
        int u = r[0]-1, v = r[1]-1;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    vector<int> finishTime(n, 0);
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
            finishTime[i] = time[i];
        }
    }
    int ans = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans = max(ans, finishTime[u]);
        for (int v : adj[u]) {
            finishTime[v] = max(finishTime[v], finishTime[u] + time[v]);
            if (--indeg[v] == 0) q.push(v);
        }
    }
    return ans;
}
};
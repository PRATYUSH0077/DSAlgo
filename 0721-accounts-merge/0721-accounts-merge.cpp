struct DSU{

    vector<int> parent,size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findparent(int u){
        if(u==parent[u]) return u;
        return parent[u]=findparent(parent[u]);
    }
    void unionfind(int u,int v){
        int pu=findparent(u);
        int pv=findparent(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv] += size[pu];
        }else{
            parent[pv]=pu;
            size[pu] += size[pv];
        }
    }

};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int> mapmail;
        DSU dsu(n+1);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(mapmail.find(email)==mapmail.end())  mapmail[email]=i;
                else{ // if email exists already mapped to a different nod
                    dsu.unionfind(i,mapmail[email]);
                }
            }
        }
       unordered_map<int, vector<string>> merged;
        for(auto it:mapmail){
            string email=it.first;
            int node=dsu.findparent(it.second);
            merged[node].push_back(email);
        }
       vector<vector<string>> ans;
       for(auto [node,emails]:merged){
            sort(emails.begin(),emails.end());
            vector<string> temp={accounts[node][0]};
            temp.insert(temp.end(),emails.begin(), emails.end());
            ans.push_back(temp);
        }
        return ans;
    }
};
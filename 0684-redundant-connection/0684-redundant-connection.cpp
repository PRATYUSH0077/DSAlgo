class Solution {
public:
    vector<int> parent,vec;
    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }
    void unionSize(int node1, int node2){
        int node1_par=findParent(node1);
        int node2_par=findParent(node2);
        if(node1_par==node2_par){
            return ;
        }else if(vec[node1_par] > vec[node2_par]){
            parent[node2_par]=node1_par;
            vec[node1_par]+= vec[node2_par];
        }else{
            parent[node1_par]=node2_par;
            vec[node2_par]+= vec[node1_par];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);    
        vec.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            vec[i]=1;
        }
        for(auto &it:edges){
            int u=it[0],v=it[1];
            int u_par=findParent(u);
            int v_par=findParent(v);
            if(u_par==v_par){
                return it;
            }
            unionSize(u,v);
        }
        return {};

    }
};
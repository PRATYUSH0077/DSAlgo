class Solution {
    vector<int> parent,size;    
public:
    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }
    void unionSize(int a,int b){
        int p1=findParent(a);
        int p2=findParent(b);
        if(p1==p2){
            return;
        }
        else if(p1>p2){
            parent[p2]=p1;
            size[p1]+=size[p2];
        }
        else{
            parent[p1]=p2;
            size[p2]+=size[p1];
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        parent.resize(c+1);
        size.resize(c+1);
        for(int i=1;i<=c;i++){
            parent[i]=i;
            size[i]=1;
        }
        for(auto it:edges){
            unionSize(it[0],it[1]);
        }
        vector<set<int>> vec(c+1);
        for(int i=1;i<=c;i++){
            vec[findParent(i)].insert(i);
        }
        vector<int> online(c+1,1);
        vector<int> ans;
        for(auto it:queries){
            int type=it[0],x=it[1];
            int rnk= findParent(x);
            if(type==1){
                if(online[x]){
                    ans.push_back(x);
                }
                else{
                    if(vec[rnk].empty()){
                        ans.push_back(-1);
                    }else{
                        int temp=*(vec[rnk].begin());
                        ans.push_back(temp);
                        // online[x]=1;
                    }
                }
            }else {
                if(online[x]){
                    online[x]=0;
                    vec[rnk].erase(x);
                }
            }
        }
        return ans;


    }
};
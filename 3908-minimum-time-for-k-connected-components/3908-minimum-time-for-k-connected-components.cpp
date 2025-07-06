class Solution {
    vector<int> parent,size;    
public:
    int findParent(vector<int>&parent,int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent,parent[node]);
    }
    void unionSize(int a,int b,vector<int>&parent,vector<int>&size){
        int p1=findParent(parent,a);
        int p2=findParent(parent,b);
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
    bool check(int n, vector<vector<int>>& edges, int k,int time){
        if(edges.empty()) return n>=k;
    //    static vector<int> parent(n),size(n);
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
        for( auto &it:edges){
            if(it[2]>time)
                unionSize(it[0],it[1],parent,size);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                cnt++;
            }
        }
        return (cnt>=k);
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int start=0,end=1e9,mid,ans=1e9;
        while(end>=start){
            mid= end- ((end-start)/2);
            // cout<<start
            if(check(n,edges,k,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};
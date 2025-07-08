#define pii pair<int,int>
class Solution {
public:
    // void dijkstras(vector<vector<int>>& adj,vector<int>& dist,map<string,int>&mp,string end){
    void dijkstras(vector<set<int>>& adj,vector<int>& dist,map<string,int>&mp,string end){
        int src=mp[end];
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                if(dis + 1 < dist[it]){
                    pq.push({dis+1,it});
                    dist[it]=dis+1;
                }
            }
        }

    }
    int Calc(string start,vector<int>&dist,map<string,int>&mp){
        int sz=start.size(),ans=1e9+7;

        for(int j=0;j<sz;j++){
            int curr=start[j]-'a';
            for(int k=0;k<26;k++){
                if(k!=curr){
                    start[j]='a'+k;
                    if(mp.find(start)!=mp.end()){
                        int ind=mp[start];
                        ans=min(ans,dist[ind]);
                    }
                    start[j]='a'+curr;
                }
            }
            
        }

        return (ans> 1e5) ? 0 : ans+2;

    }
    // void printAdj(vector<vector<int>>&adj){
    void printAdj(vector<set<int>>&adj,vector<int>&dist){
        int n=adj.size();
        for(int i=0;i<n;i++){
            for(auto &it:adj[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        for(auto it:dist){
            cout<<it<<" ";
        }
    }
    int ladderLength(string start, string end, vector<string>& word) {
        map<string,int> mp;
        int n=word.size(),sz=start.size();
        for(int i=0;i<n;i++){
            mp[word[i]]=i;
        }
        if(mp.find(end)==mp.end()){
            return 0;
        }

        // make graph
        // vector<vector<int>> adj(n);
        vector<set<int>> adj(n);
        for(int i=0;i<n;i++){
            string temp=word[i];
            for(int j=0;j<sz;j++){
                int curr=word[i][j]-'a';
                for(int k=0;k<26;k++){
                    if(k!=curr){
                        temp[j]='a'+k;
                        if(mp.find(temp)!=mp.end()){
                            int ind=mp[temp];
                            // adj[i].push_back(ind);
                            // adj[ind].push_back(i);
                            adj[i].insert(ind);
                            adj[ind].insert(i);
                        }
                        temp[j]='a'+curr;
                    }
                }

            }
        }
        //minimum dist of end from each word from graph
        vector<int> dist(n,1e7);
        dijkstras(adj,dist,mp,end);
        // printAdj(adj,dist);
        int ans=Calc(start,dist,mp);
        return ans;



    }
};
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& arr) {
        int m=arr.size(),n=arr[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1){
                    q.push({0,{i,j}});
                }
            }
        }
        int delx[]={0,1,0,-1};
        int dely[]={1,0,-1,0};
        while(!q.empty()){
            int height=q.front().first;
            pair<int,int> cor=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newx=cor.first+delx[i],newy=cor.second+dely[i];
                if(newx>=0 && newx<m && newy>=0 && newy<n && 
                    arr[newx][newy]==0 && vis[newx][newy]==0){
                    q.push({height+1,{newx,newy}});
                    // cout<<newx<<" "<<newy<<" "<<height<<endl;
                    vis[newx][newy]=height+1;
                }
            }
        }
        return vis;
    }
};
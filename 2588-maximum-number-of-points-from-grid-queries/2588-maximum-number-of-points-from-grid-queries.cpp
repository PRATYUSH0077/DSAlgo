#define pii pair<int,pair<int,int>>
class Solution {
public:
    bool isValid(int x,int y,int m,int n){
        return (x>=0 && x<m && y>=0 && y<n);
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m=grid.size(),n=grid[0].size();
        int cnt=0,last_visit=-1;

        map<int,int> mp;
        vector<vector<int>> visited(m,vector<int>(n,0));
        priority_queue<pii,vector<pii>,greater<pii>> q;
        int delrow[]={0,1,0,-1};
        int delcol[]={1,0,-1,0};

        q.push({grid[0][0],{0,0}});
        visited[0][0]=1;

        while(!q.empty()){
            int x=q.top().second.first;
            int y= q.top().second.second;
            q.pop();
            if( grid[x][y]>last_visit) 
            {
                mp[grid[x][y]]=cnt;
                last_visit=grid[x][y];
            }
            cnt++;

            for(int del=0;del<4;del++){
                int newx=x+delrow[del],newy=y+delcol[del];
                if(isValid(newx,newy,m,n) && !visited[newx][newy]){
                    q.push({grid[newx][newy],{newx,newy}});
                    visited[newx][newy]=1;
                }
            }
        }
        mp[1e6+5]=m*n;
        int k=queries.size();
        vector<int> ans(k);
        for(int i=0;i<k;i++){
            auto it=mp.lower_bound(queries[i]);
            if(i==0){
                cout<<it->first<<" "<<it->second<<"\n";
            }
            ans[i]=it->second;
        }
        return ans;
    }
};
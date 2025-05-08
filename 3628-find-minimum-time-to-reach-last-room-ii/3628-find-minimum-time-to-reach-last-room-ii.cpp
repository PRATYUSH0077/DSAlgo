#define ll long long
#define pipii pair<int,pair<int,pair<int,int>>>
class Solution {
public:
    bool isValid(int n,int m,int nrow,int ncol){
        return (nrow>=0 && nrow<n && ncol>=0 && ncol<m);
    }
    int minTimeToReach(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        priority_queue<pipii,vector<pipii>,greater<pipii>> pq;
        // pq.push({{0,1},{0,0}});
        pq.push({0,{1,{0,0}}});
        while(!pq.empty()){
            int i=pq.top().second.second.first;
            int j=pq.top().second.second.second;
            int time=pq.top().first;
            int inc=pq.top().second.first;
            // cout<<i<<" "<<j<<" "<<time<<" "<<inc<<endl;
            if(i==0 && j==0){
            }
            else{
                if(inc==1){
                    time=max(time,arr[i][j]+2);
                }else{
                    time=max(time,arr[i][j]+1);
                }
            }
            // cout<<i<<" "<<j<<" "<<time<<" "<<inc<<endl;
            pq.pop();
            if(i==n-1 && j==m-1){
                return time;
            }
            if(vis[i][j]){
                continue;
            }
            vis[i][j]=1;
            for(int k=0;k<4;k++){
                int nrow=i+delrow[k],ncol=j+delcol[k];
                if(isValid(n,m,nrow,ncol) 
                    && !vis[nrow][ncol]
                ){    
                    if(inc==1){
                       pq.push({time+1,{2,{nrow,ncol}}});
                    }else {
                       pq.push({time+2,{1,{nrow,ncol}}});
                    }
                }
            }                
        }
        
        return -1;
    }
};
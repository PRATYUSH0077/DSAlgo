class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(auto &it:edges){
            int u=it[0],v=it[1],cost=it[2];
            dist[u][v]=cost;
            dist[v][u]=cost;
        }

        for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					dist[i][j] = min(dist[i][j],
					                   dist[i][k] + dist[k][j]);
				}
			}
		}


        int count=n+1,ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]!=1e9 && dist[i][j]<=distanceThreshold  ) 
                    cnt++;
            }
            // cout<<i<<" "<<cnt<<endl;
            if(cnt<= count){
                ans=i;
                count=cnt;
            }
        }
        return ans;
    }
};
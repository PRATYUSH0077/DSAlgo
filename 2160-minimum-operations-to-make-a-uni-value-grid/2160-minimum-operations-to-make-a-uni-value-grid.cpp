class Solution {
public:
    int chck(int mid,int n,int x,vector<int>&vec){
        int ans=0;
        for(auto it:vec){
            if((abs(mid-it))%x==0)
                ans+=( (abs(mid-it))/x);
            else
                return -1;
        }
        return ans;
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size(),n=grid[0].size();

        vector<int> vec(m*n);
        int i=0;
        for(auto it:grid){
            for(auto it2:it){
                vec[i]=it2;
                i++;
            }
        }
        sort(vec.begin(),vec.end());
        int len= m*n;
        if(len%2){
            int ans=chck(vec[len/2],len,x,vec);
            return ans;
        }
        int ans=chck(vec[len/2],len,x,vec);
        if(ans!=-1)
            return ans;
        
        ans=chck(vec[(len-1)/2],len,x,vec);
        return ans;
        
    }
};
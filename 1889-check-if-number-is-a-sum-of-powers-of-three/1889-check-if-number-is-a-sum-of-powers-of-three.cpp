class Solution {
public:
    bool rec(int n,int len,vector<int>&vec,vector<int>&vis){
        if(n==0)
            return true;
        
        bool ans=false;
        for(int i=0;i<len;i++){
            if(vec[i]<=n && !vis[i]){
                vis[i]=1;
                ans= ans || rec(n-vec[i],len,vec,vis);
                vis[i]=0;
            }else{
                break;
            }
        }
        return ans;
    }
    bool checkPowersOfThree(int n) {
        vector<int> vec(16,0);
        for(int i=0;i<=15;i++){
            vec[i]=(pow(3,i));
        }
        vector<int> vis(16,0);
        // bool ans=rec(n,16,vec,vis);
        // return ans;

        while(n>0){
            if(n%3==2)
                return false;
            n/=3;
        }
        return true;
    }
};
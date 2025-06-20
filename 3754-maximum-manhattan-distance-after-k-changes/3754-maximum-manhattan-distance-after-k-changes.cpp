class Solution {
public:
    int maxDistance(string s, int k) {
        int N=0,S=0,W=0,E=0,ans=-1;
        for(auto it:s){
            N+= (it=='N');
            S+= (it=='S');
            E+= (it=='E');
            W+= (it=='W');
            int tempk=k,temp=abs(N-S)+abs(E-W);
            temp+= 2*min(tempk,min(N,S));
            tempk-=min(tempk,min(N,S));
            temp+= 2*min(tempk,min(E,W));
            ans=max(ans,temp);        
        }
        return ans;
        
    }
};
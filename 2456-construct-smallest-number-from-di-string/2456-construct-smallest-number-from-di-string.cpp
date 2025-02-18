class Solution {
public:
    bool recursion(int i,int n,string &ans,string temp,string s,vector<int>&vis){
        if(i==n){
            ans=temp;
            return true;
        }
        bool flag=false;
        for(int j=1;j<=9;j++){
            if(!vis[j] && s[i]=='I' && j>(temp.back()-'0')){
                temp+= ('0'+j);
                vis[j]=1;
                flag=recursion(i+1,n,ans,temp,s,vis);
                vis[j]=0;
                temp.pop_back();
            }else if(!vis[j] && s[i]=='D' && j<(temp.back()-'0')){
                temp+= ('0'+j);
                vis[j]=1;
                flag=recursion(i+1,n,ans,temp,s,vis);
                vis[j]=0;
                temp.pop_back();
            }
            if(flag){
                break;
            }
        }
        return flag;
    }
    string smallestNumber(string s) {
        int n=s.size();        
        vector<int> vis(10,0);
        string ans,temp;
        bool flag=false;
        for(int i=1;i<=9;i++){
            temp+= ('0'+i);
            vis[i]=1;
            flag=recursion(0,n,ans,temp,s,vis);
            vis[i]=0;
            temp.pop_back();
            if(flag)
                break;
        }
        return ans;
    }
};
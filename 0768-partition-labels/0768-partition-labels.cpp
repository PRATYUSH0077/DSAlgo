class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<pair<int,int>> freq(26,{-1,-1});
        for(int i=0;i<n;i++){
            int ind=s[i]-'a';
            if(freq[ind].first==-1){
                freq[ind]={i,i};
            }else{
                freq[ind].second=i;
            }
        }
        vector<int> ans;
        int prev=-1,curr=0;
        while(curr<n){
            bool flag=true;
            for(int i=0;i<26;i++){
                if(freq[i].first<=curr && freq[i].second>curr){
                    curr=max(curr,freq[i].second);
                    flag=false;
                }
            }
            if(flag){
                // cout<<curr<<" "<<prev<<endl;
                ans.push_back(curr-prev);
                prev=curr;
                curr++;
            }
        }
        return ans;

    }
};
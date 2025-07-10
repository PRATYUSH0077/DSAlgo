class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int> vec;
        if(startTime[0]!=0){
            vec.push_back(startTime[0]);
        }
        for(int i=1;i<n;i++){
            vec.push_back(startTime[i]-endTime[i-1]);
        }
        if(endTime[n-1]!=eventTime){
            vec.push_back(eventTime-endTime[n-1]);
        }
        int sz=vec.size(),i=0,j=0,temp=0,ans=0;
        while(j<sz){
            cout<<i<<" "<<j<<endl;
            if(j-i+1 <= k+1){
                temp+=vec[j];
                j++;
            }else{
                // temp+= vec[j];
                ans=max(ans,temp);
                temp-=vec[i];
                i++;
            }
        }
        ans=max(ans,temp);
        return ans;
    }
};
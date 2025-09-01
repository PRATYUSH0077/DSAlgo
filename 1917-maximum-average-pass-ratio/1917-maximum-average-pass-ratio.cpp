#define pdi pair<double,pair<double,double>>

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int k) {
        int n=classes.size();
        priority_queue<pdi> pq;
        for(auto it:classes){
            double change=((double)(it[0]+1)/(double)(it[1]+1)-(double)(it[0])/(double)(it[1]));
            pq.push({change,{it[0],it[1]}});
        }
        while(k--){
            auto it=pq.top().second;
            pq.pop();
            it.first++,it.second++;
            double change=((it.first+1)/(it.second+1)-(it.first)/(it.second));
            pq.push({change,it});
        }
        double res=0;
        while(!pq.empty()){
            auto it=pq.top().second;
            pq.pop();
            res+= (it.first/it.second);
        }
        return res/n;

    }
};
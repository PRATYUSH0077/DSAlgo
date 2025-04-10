#define ll long long
class Solution {
public:
    ll dp[18][2];
    ll fun(string &num,string &s,ll n,int limit,int tight){
        if(num.size()<s.size()){
            return 0;
        }
        if(dp[n][tight]!=-1){
            return dp[n][tight];
        }
        ll ans=0;
        ll ub= (tight ? num[num.size()-n]-'0' : 1LL*limit);
        if(n==1)
        {
            int num2= s[s.size()-n]-'0';
            if(num2>ub){
                return 0LL;
            }
            return 1LL;
        }
        if(n<=s.size()){
            if(tight){
                int num2= s[s.size()-n]-'0';
                if(num2>ub){
                    return 0LL;
                }else if(num2==ub){
                    ans+= fun(num,s,n-1,limit,1);
                }else{
                    return 1LL;
                }
            }else{
                return 1LL;
            }
        }else{
            for(int i=0;i<=ub && i<=limit;i++){
                ans+= fun(num,s,n-1,limit,tight & (i==ub));
            }
        }

        return dp[n][tight]=ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string begin=to_string(start-1);
        string end=to_string(finish);
        memset(dp,-1,sizeof(dp));
        ll res1=fun(begin,s,begin.size(),limit,1);
        memset(dp,-1,sizeof(dp));
        ll res2=fun(end,s,end.size(),limit,1);
        return res2-res1;
    }
};
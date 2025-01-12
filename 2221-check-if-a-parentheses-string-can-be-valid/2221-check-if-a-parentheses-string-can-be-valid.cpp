class Solution {
public:
    bool canBeValid(string s, string locked) {
        // int cannot=0,can=0
        int n=s.size();
        stack<int> can,cannot;
        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                can.push(i);
            }else if(locked[i]=='1' &&s[i]==')'){
                if(!cannot.empty())
                    cannot.pop();
                else if(!can.empty())
                    can.pop();
                else
                    return false;
            }else if(locked[i]=='1' && s[i]=='('){
                cannot.push(i);
            }
        }
        while(!cannot.empty()){
            if(can.empty())
                return false;
            else if(can.top() > cannot.top()){
                can.pop();
                cannot.pop();
            }else
                return false;
        }
        return (can.size()%2==0);
    }
};
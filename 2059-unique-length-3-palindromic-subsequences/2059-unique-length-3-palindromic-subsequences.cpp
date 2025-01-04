class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first_occurance(26,-1),last_occurance(26,-1);
        int lenght=s.size();
        for(int index=0;index<lenght;index++){
            if(first_occurance[s[index]-'a']==-1){
                first_occurance[s[index]-'a']=index;
            }else{
                last_occurance[s[index]-'a']=index;
            }
        }
        int answer=0;
        for(int character=0;character<26;character++)
        {
            set<char> unique;
            for(int index=first_occurance[character]+1;index<last_occurance[character];index++)
            {
                unique.insert(s[index]);
            }
            answer+= unique.size();
        }
        return answer;
    
    }
};
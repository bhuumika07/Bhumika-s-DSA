class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        int close = 0;
        string ans = "";
        int total= 0;
        int req = 0;
        for( char c : s) if( c == ')') total++;
        for( char c : s)
        {
            if( c != '(' && c != ')') ans += c;
            else 
            {
                if( c == '(' && total - req > 0)
                {
                    open++;
                    req++;
                    ans+=c;
                }
                else if( c == ')' && open > 0)
                {
                    open--;
                    req--;
                    total--;
                    ans+=c;
                }
                else if( c == ')') total--;
            }
        }
        return ans;
        
    }
};
class Solution {
public:
    int minInsertions(string s) {
        int open=0;
        int close=0;
        int ans=0;
        for( char c : s)
        {
            if( c == '(' && close == 1 && open > 0)
            {
                ans += 2 - close;
                open--; close=0;
            }
            if( c == '(') open++;
            else close++;
            if( open == 0 && close > 0)
            {
                ans++;
                open++;
            }
            if( close == 2 && open > 0)
            {
                close=0;
                open--;
            }   
        }
        if( open != 0) ans += 2*open - close;
        return ans;
    }

};
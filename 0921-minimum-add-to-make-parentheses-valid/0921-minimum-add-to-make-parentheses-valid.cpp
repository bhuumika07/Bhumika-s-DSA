class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int close = 0;
        int ans  = 0;
        for( char c : s)
        {
            if( c =='(') open++;
            else close++;
            if( close > open )
            {
                int diff = close - open;
                ans+=diff;
                open=0;
                close=0;
            }
        }
        if( open > close ) ans +=(open-close);
        return ans;
    }
};
class Solution {
public:
    int dp[2001];
    bool isPalindrome( string &s , int start , int end)
    {
        while( start <= end)
        {
            if(s[start] != s[end]) return 0;
            start++;
            end--;
        }
        return 1;
    }
    int doit( string &s , int idx)
    {
        if( idx == s.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int ans = INT_MAX;
        for( int i=idx ; i<s.size();i++)
        {
            if( isPalindrome( s, idx , i))
            {
                ans =min(ans , 1 + doit( s , i+1)) ;
            }
        }

        return dp[idx] = ans;

    }
    int minCut(string s) {
        memset( dp , -1 , sizeof(dp));
        return doit( s, 0) - 1;
    }
};
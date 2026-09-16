class Solution {
public:
    int dp[2001];
   bool checkit(string &s, int &left, int &right)
    {
        int end = left + right;
        if (end > s.size()) return 0;
        for (int i = left; i < left + right / 2; i++)
        {
            if (s[i] != s[end - 1 - (i - left)])
            return 0;
        }
        return 1;
    }
    int solve( string &s , int start , int k)
    {
        if(start + k >  s.size()) return 0;
        if( dp[start] != -1) return dp[start];
        int take=0;
        int dont= 0;
         for(int i= k; start + i <= s.size(); i++)
        {
            if(checkit(s, start, i))
            {
                take = max(take, 1 + solve(s, start + i, k));
            }
        }
        dont = solve(s, start+1 , k);

        return dp[start] = max( take , dont);
    }
    int maxPalindromes(string s, int k) {
        if(k == 1) return s.size();
        memset( dp , -1 , sizeof(dp));
        return solve( s , 0 , k);
        
    }
};
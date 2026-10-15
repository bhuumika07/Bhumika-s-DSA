class Solution {
public:
    int climbStairs(int n) {
        int ans = 0;
        int back = 0;
        int prev = 1;
        for( int i=1; i<=n; i++)
        {
           ans = back + prev;
           back = prev;
           prev = ans;
        }
        return ans;
    }
};
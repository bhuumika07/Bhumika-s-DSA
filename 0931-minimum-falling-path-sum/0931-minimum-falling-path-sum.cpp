class Solution {
public:
    int dp[101][101];
    int doit( vector<vector<int>>&matrix , int r , int c)
    {
        if(  c >= matrix.size() || c < 0) return INT_MAX;
        if( r >= matrix.size()) return 0;
        if( dp[r][c] != 1e9) return dp[r][c];
        int dgleft = doit(matrix , r+1,c-1 );
        int down = doit( matrix, r+1 , c);
        int dgright = doit( matrix ,r+1 , c+1);

        return dp[r][c] = matrix[r][c] + min( dgleft , min( down , dgright));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        fill(&dp[0][0], &dp[0][0] + 101 * 101, 1e9);
        for(int i=0; i<matrix.size();i++)
        {
            ans = min( ans,doit(matrix ,0 , i));
        }
        return ans;
    }
};
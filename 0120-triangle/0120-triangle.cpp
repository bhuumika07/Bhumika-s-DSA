class Solution {
public:
    int dp[201][201];
    int doit( vector<vector<int>>&triangle , int r , int c )
    {
        if( c > r) return INT_MAX;
        if( r >= triangle.size()) return 0;
        if( dp[r][c] != INT_MIN) return dp[r][c];
        int below = doit( triangle , r+1 , c);
        int right = doit( triangle , r+1 , c+1);

        return dp[r][c] = triangle[r][c] + min(below , right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        fill( &dp[0][0], &dp[0][0] + 201*201 , INT_MIN);
        return doit(triangle , 0 , 0);   
    }
};
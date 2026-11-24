class Solution {
public:
    int dp[101][101];
    int doit( vector<vector<int>>&matrix , int row , int col){
        int n = matrix.size();
        int m = matrix[0].size();
        if(col >= m || col < 0) return 1e9;
        if( row == n-1) return dp[row][col] = matrix[row][col];
        if(dp[row][col] != INT_MAX) return dp[row][col];
        int below = doit(matrix , row+1 , col);
        int left = doit(matrix,row+1,col-1);
        int right = doit(matrix , row+1 , col +1);

        return dp[row][col] = matrix[row][col] + min(below , min(left,right)); 

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
       fill(&dp[0][0], &dp[0][0] + 101 * 101, INT_MAX);
       int n = matrix.size();
       int m = matrix[0].size();
        int ans  = INT_MAX;
       for( int i = 0; i<m; i++) {
        ans = min( ans , doit(matrix , 0 , i));
       }
       return ans;
    }
};
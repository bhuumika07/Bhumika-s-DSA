class Solution {
public:

    int doit(vector<vector<int>>&triangle , int row , int col,  vector<vector<int>>&dp){
        if( row == triangle.size()-1 ) return triangle[row][col];
        if(dp[row][col] != INT_MAX) return dp[row][col];
        int down = doit(triangle , row+1 , col,dp);
        int next = doit( triangle , row+1,col+1,dp);
        return dp[row][col]= triangle[row][col] + min(down,next);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(201,vector<int>(201,INT_MAX));
        return doit(triangle , 0 , 0,dp);
    }
};
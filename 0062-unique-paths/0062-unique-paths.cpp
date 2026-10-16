class Solution {
public:
    int uniquePaths(int m, int n) {
        // space optimization approach:
        // for every index , i just required the previious row and pervious column and its a golden chance to space optimize it .
        // i will keep a 1D dp vector for the row above and temp vector for current row.
       vector<int>dp( n , 1);
       for( int i=1; i<m ; i++)
       {
        vector<int>temp( n , 0);
        temp[0] = dp[0];
        for( int j=1; j<n; j++)
        {
           temp[j] = dp[j] + temp[j-1];
        }
        dp=temp;
       }
       return dp[n-1];

    }
};
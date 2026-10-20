class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n = matrix.size();
       vector<vector<int>>sums(n ,vector<int>( n ,INT_MAX));
       int ans = INT_MAX;
       for( int i = 0; i< n; i++)
       {
        for( int j = 0; j< n ; j++)
        {
            if( i == 0)
            {
                sums[i][j] = matrix[i][j];
            }
            else
            {
                if( j > 0)
                {
                    sums[i][j] = min( sums[i][j] , matrix[i][j] + sums[i-1][j-1]);
                }
                if(j+1 < n)
                {
                    sums[i][j]=min( sums[i][j] , matrix[i][j] + sums[i-1][j+1]);
                }
                sums[i][j] = min( sums[i][j] , matrix[i][j] + sums[i-1][j]);
                
            }
            if( i == n-1)
            {
                ans = min( ans , sums[i][j]);
            }
        }
       }
       return ans;
    }
};
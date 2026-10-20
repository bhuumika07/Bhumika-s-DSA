class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n = matrix.size();
       vector<int>row(n);
       int ans = INT_MAX;
       for( int i = 0; i< n; i++)
       {
        vector<int>temp(n , INT_MAX);
        for( int j = 0; j< n ; j++)
        {
            if( i == 0) temp[j] = ( matrix[i][j]);
            else
            {
                if( j > 0) temp[j] = min( temp[j] , row[j-1]);
                if( j+1 < n) temp[j] =min( temp[j] , row[j+1]);
                temp[j] = min( temp[j] , row[j]);
                temp[j] += matrix[i][j];
            }
            if( i == n-1) ans = min( ans , temp[j]);
        }
        row = temp;
       }
       return ans;
    }
};
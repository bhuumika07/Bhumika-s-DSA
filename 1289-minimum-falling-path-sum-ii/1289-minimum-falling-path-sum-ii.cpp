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
               for(int k = 0; k < n; k++)
                {
                    if(k != j)
                    temp[j] = min(temp[j], row[k]);
                }
                temp[j] += matrix[i][j];
            }
            if( i == n-1) ans = min( ans , temp[j]);
        }
        row = temp;
       }
       return ans;
    }
};
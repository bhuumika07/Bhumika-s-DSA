class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>sums(n , vector<int>(n,INT_MAX));
        int ans = INT_MAX;
        for(int i=0; i<n; i++)
        {
            for( int j = 0; j<=i; j++)
            {
                if( i == 0) sums[i][j] = triangle[i][j];
                else{
                    if(sums[i-1][j] != INT_MAX) sums[i][j] = triangle[i][j] + sums[i-1][j];
                    if(j > 0) sums[i][j] = min( sums[i][j] , triangle[i][j] + sums[i-1][j-1]);
                }
                if( i == n-1) ans = min( ans , sums[i][j]);
            }
        }
        return ans;
        
    }
};
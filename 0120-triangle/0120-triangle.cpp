class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ans = INT_MAX;
        vector<int>rows(n);
        for(int i=0; i<n; i++)
        {
           vector<int>temp(n);
           for( int j = 0; j<=i; j++)
           {
            if( i == 0) temp[j] = triangle[i][j];
            else{
                // i can access j jo mere last i se chotta ho.
                if( j <= i-1) temp[j] = rows[j];
                else temp[j] = INT_MAX;
                if( j > 0) temp[j] = min( temp[j] , rows[j-1]);
                temp[j] += triangle[i][j];
            }
             if( i == n-1) ans = min( ans , temp[j]);
           }
           rows = temp;
        }
        return ans;
        
    }
};
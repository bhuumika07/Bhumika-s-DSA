class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
      // every cell will be considered as a culprit resposnible for forming a square ; however , the posibilty will also depend on the neighbouring cells as well.
      long long count = 0;
      int n = matrix.size();
      int m = matrix[0].size();
      vector<vector<int>>dp( n , vector<int>(m , 0));
      for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            if(i==0 || j ==0 || matrix[i][j] == 0) dp[i][j] = matrix[i][j];
            else{
                int pick = min(dp[i-1][j-1] , min( dp[i-1][j] , dp[i][j-1]));
                dp[i][j] += pick + 1;
            }
            count+=dp[i][j];
        }
      }
      return count;
    }
};
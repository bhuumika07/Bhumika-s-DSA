class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
      // every cell will be considered as a culprit resposnible for forming a square ; however , the posibilty will also depend on the neighbouring cells as well.
      long long count = 0;
      int n = matrix.size();
      int m = matrix[0].size();
      vector<int>rows(m,0);
      for(int i=0; i<n; i++){
        vector<int>temp(m,0);
        for(int j=0; j<m;j++){
            if(i==0 || j ==0 || matrix[i][j] == 0) temp[j] = matrix[i][j];
            else{
                int pick = min(rows[j-1] , min( rows[j] , temp[j-1]));
                temp[j]+= (pick + 1);
            }
            count+=temp[j];
        }
        rows=temp;
      }
      return count;
    }
};
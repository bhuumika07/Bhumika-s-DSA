class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();
        vector<int>above(m,0);
        int maxi = 0;
        for(int i=0; i<n;i++){
            vector<int>temp(m,0);
            for(int j=0; j<m;j++){
                if( i == 0 || j == 0 || matrix[i][j] == '0') temp[j] = matrix[i][j] - '0';
                else{
                    int pick = min( above[j-1] , min(temp[j-1] , above[j]));
                    temp[j] +=(pick+1);
                }
                maxi = max( maxi ,temp[j]);
            }
            above=temp;
        }
        return maxi*maxi;
    }
};
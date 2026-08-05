class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0;
        int right = n - 1;
        int up = 0;
        int down = n - 1;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int num = 1;

        while (left <= right && up <= down) {
            for (int i = left; i <= right; i++) {
                matrix[up][i] = num;
                num++;
            }
            up++;
            for (int i = up; i <= down; i++) {
                matrix[i][right] = num;
                num++;
            }
            right--;
            if( left <= right)
            {
                for (int i = right; i >= left; i--) {
                matrix[down][i] = num;
                num++;
            }
            down--;
            }
            if( up <= down)
            {
                for(int i=down; i>= up; i--)
                {
                matrix[i][left]=num;
                num++;
            }
            left++;
            }
         
        }
        return matrix;
    }
};
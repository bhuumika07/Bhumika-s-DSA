class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();vector<int>rows(n); 
        int first = -1; int second = -1;
        for(int i = 0; i<n; i++)
        {
            vector<int>temp(n); int f =-1; int s= -1;
            for(int j=0; j<n;j++)
            {
                if( i == 0){
                    temp[j]=grid[i][j];
                }
                else
                {
                    if(j != first)
                    {
                        temp[j] = grid[i][j] + rows[first];
                    }
                    else temp[j] = grid[i][j] + rows[second];
                }
                if(f == -1) f = j;
                else if(temp[j] <= temp[f])
                {
                    s = f;
                    f = j;
                }
                else if(s == -1 || temp[j] <= temp[s])  s = j;

            }
            rows = temp;
            first =f;
            second=s;  
        }
        return rows[first];
        
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        int cnt=0;
        // first i will store all the rotten oranges.
        for( int i=0; i<n;i++)
        {
            for( int j=0; j<m;j++)
            {
                if( grid[i][j]==2)
                {
                    q.push( {{i,j},0});
                    visited[i][j]=1;
                }
                if(grid[i][j]==1) cnt++;
            }
        }
        int drow[] = {-1, 0, 1, 0};
        int dcol[]={ 0, -1, 0, 1};
        int ans=0;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int t= it.second;
            ans=max(ans,t);
            for( int i=0; i<4;i++)
            {
               int nrow = row + drow[i];
               int ncol= col + dcol[i];
               if(nrow >=0 && nrow<n && ncol >=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1)
               {
                // grid[nrow][ncol]=2;
                cnt--;
                visited[nrow][ncol]=1;
                q.push( {{nrow,ncol}, t+1});
               }
               
            }
        }

        // for( int i=0; i<n;i++)
        // {
        //     for( int j=0; j<m;j++)
        //     {
        //         if( grid[i][j]==1) return -1;
        //     }
        // }
        if( cnt != 0) return -1;

        return ans;
    }
};
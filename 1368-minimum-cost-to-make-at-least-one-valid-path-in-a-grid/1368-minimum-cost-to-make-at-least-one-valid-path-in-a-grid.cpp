class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
       int rsize = grid.size();
       int csize = grid[0].size();
       int rows[]={-1,0,1,0};
       int cols[]={0,-1,0,1};
       deque< tuple<int,int,int> > q;
       q.push_back({0,0,0});
       vector<vector<int>>visited(rsize , vector<int>(csize,INT_MAX));
       visited[0][0]=0;
        int mini=INT_MAX;
       while(!q.empty()) 
       {
        auto [r,c,cost]=q.front();
        q.pop_front();

        if( visited[r][c] < cost) continue;
        if( r == rsize-1 && c==csize-1) return cost;
       
        int i,j;
        if(grid[r][c] == 1)
        {
            i=r;
            j=c+1;
        }
        else if( grid[r][c] ==2)
        {
            i=r;
            j=c-1;
        }
        else if( grid[r][c] == 3)
        {
            i=r+1;
            j=c;
        }
        else
        {
            i=r-1;
            j=c;
        }
        for( int k=0; k<4;k++)
        {
            int nrow = r + rows[k];
            int ncol = c + cols[k];
            if( nrow >=0 && nrow < rsize && ncol >=0 && ncol < csize)
            {
                int extra=0;
                if(i>=0 && i<rsize && j>=0 && j<csize &&  i==nrow && j== ncol) extra=0;
                else extra=1;
                if( visited[nrow][ncol] <= cost + extra) continue;
                visited[nrow][ncol] = cost+extra;
                if( extra == 0) q.push_front({nrow,ncol,cost});
                else q.push_back({nrow,ncol,cost+extra});
            }
        }

       }
       return -1;
    }
};
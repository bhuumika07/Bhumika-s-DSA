class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        unordered_map< char , int > keys;
        int rsize = grid.size();
        int csize = grid[0].size();
        int id=0;
        int sr=-1;
        int sc=-1;
        int rows[]={-1,0,1,0};
        int cols[]={0,-1,0,1};
        for( int i=0; i<rsize;i++)
        {
            for( int j=0;j<csize;j++)
            {
                if( grid[i][j] =='@')
                {
                    sr=i;
                    sc=j;
                }
                else if(grid[i][j]>=97 && grid[i][j] <= 122)
                {
                   keys[grid[i][j]] = id++;
                }
            }
        }

        int mask = (1<<id)-1;
      vector<vector<vector<bool>>> visited(
        rsize,
    vector<vector<bool>>(
        csize,
        vector<bool>(1 << id, false)
    )
);
        
        queue< tuple<int,int,int,int> > q;
        q.push({sr,sc,0,0});
        visited[sr][sc][0] = true;

        while(!q.empty())
        {
            auto [r,c,state,steps] = q.front();
            q.pop();
            if( state == mask ) return steps;

            for(int i=0;i<4;i++)
            {
                int nrow = r + rows[i];
                int ncol = c + cols[i];
                int currState = state;
                if(nrow < 0 || ncol <0 || ncol >=csize || nrow >= rsize) continue;

                if(grid[nrow][ncol] == '#') continue;

                if(grid[nrow][ncol] >= 97 && grid[nrow][ncol] <= 122)
                {
                    int val = keys[grid[nrow][ncol]];
                    currState = currState | (1 <<val);
                }
                else if( grid[nrow][ncol] >= 65 && grid[nrow][ncol] <=90)
                {
                    // int check = grid[nrow][ncol] + 32;
                    int val = keys[grid[nrow][ncol] + 32];
                    if(!( currState & (1<<val))) continue;
                }

                if(visited[nrow][ncol][currState]) continue;
                q.push({nrow,ncol,currState,steps+1});
                visited[nrow][ncol][currState]=1;
            }
        }
        return -1;

    }
};
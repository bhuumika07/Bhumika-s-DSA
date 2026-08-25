class Solution {
public:
    int rows[4]={-1,0,1,0};
    int cols[4]={0,-1,0,1};
    int components( int row , int col , vector<vector<int>>&grid , vector<vector<bool>>&visited,int s)
    {
        int count=0;
        int rsize = grid.size();
        int csize = grid[0].size();
        queue<pair<int,int>> q;
        visited[row][col]=1;
        q.push({row,col});
        grid[row][col]=s;
        while(!q.empty())
        {
            int r1= q.front().first;
            int c1 = q.front().second;
            q.pop();
            count++;
            for( int i = 0; i<4; i++)
            {
                int nrow = rows[i] + r1;
                int ncol = cols[i] + c1;

                if( nrow >=0 && nrow <rsize && ncol >=0 && ncol < csize && !visited[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    visited[nrow][ncol]=1;
                    grid[nrow][ncol]=s;
                    q.push( {nrow , ncol});
                }
            }
        }
        return count;

    }
    int largestIsland(vector<vector<int>>& grid) {
        int rsize = grid.size();
        int csize = grid[0].size();
        vector<vector<bool>>visited(rsize , vector<bool>(csize,0));
        int s=1;
        int size=0;
        unordered_map<int,int>mark;
        for( int i=0; i<rsize ; i++)
        {
            for( int j=0;j<csize;j++)
            {
                if(!visited[i][j] && grid[i][j] == 1) 
                {
                    size = components(i,j,grid , visited,s); 
                    mark[s]=size;
                    s++;
                }
            }
        }
        bool found=0;
        int maxi=0;
        for( int i=0; i<rsize;i++)
        {
            for( int j=0; j<csize; j++)
            {
                if(grid[i][j] == 0)
                {
                    found=1;
                    int sum=0;
                    unordered_set<int>put;
                    for( int k=0; k<4; k++)
                    {
                        int nrow = i+rows[k];
                        int ncol =j + cols[k];
                        if(nrow >=0 && nrow < rsize && ncol >=0 && ncol < csize)
                        {
                            if( put.find( grid[nrow][ncol]) == put.end())
                            {
                                put.insert(grid[nrow][ncol]);
                                sum+=mark[grid[nrow][ncol]];
                            }
                        }
                    }  
                    maxi=max(maxi , sum+1); 
                }
            }
        }
        if( !found) return size;
        return maxi;
    }
};
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int rsize = grid.size();
        int csize = grid[0].size();
        int rows[]={-1,0,1,0};
        int cols[]={0,-1,0,1};
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>reached(rsize , vector<int>( csize , INT_MAX));

        while(!pq.empty())
        {
            int obs = pq.top().first;
            int r1 = pq.top().second.first;
            int c1 = pq.top().second.second;
            pq.pop();

            if( reached[r1][c1] < obs) continue;

            for( int i=0; i<4;i++)
            {
                int nrow = r1 + rows[i];
                int ncol = c1 + cols[i];
                
                if( nrow >=0 && nrow < rsize && ncol >=0 && ncol < csize)
                {
                    if(grid[nrow][ncol] == 0)
                    {
                        if( reached[nrow][ncol] > obs) { reached[nrow][ncol]=obs;pq.push({obs , {nrow,ncol}});}
                    }
                    else
                    {
                         if( reached[nrow][ncol] > obs+1) { reached[nrow][ncol]=obs+1;pq.push({obs +1 , {nrow,ncol}}); }  
                    }
                }
            }
        }
        return reached[rsize-1][csize-1];
        
    }
};
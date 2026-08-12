class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if( grid[0][0] == 1) return -1;
        int rows[]={-1,0,1,0,-1,-1,1,1};
        int cols[]={0,-1,0,1,-1,1,-1,1};
        int rsize= grid.size();
        int csize = grid[0].size();
        priority_queue< pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>> , greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>>reached(rsize , vector<int>(csize,1e9));
        pq.push({1, {0,0}});
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int r1 = pq.top().second.first;
            int c1 = pq.top().second.second;
            pq.pop();
            if( reached[rsize-1][csize-1] < dis) return reached[rsize-1][csize-1];
            if( r1 == rsize-1 && c1==csize-1) return dis;
            for(int i=0; i<8; i++)
            {
                int nrow = r1 + rows[i];
                int ncol = c1 + cols[i];
                if( nrow >= 0 && nrow < rsize && ncol >= 0 && ncol < csize && grid[nrow][ncol]==0)
                {
                    if( reached[nrow][ncol] > dis+1)
                    {
                        reached[nrow][ncol] = dis+1;
                        pq.push( {dis+1 , {nrow,ncol}});
                    }
                }
            }
           
        }
        if( reached[rsize-1][csize-1] == 1e9) return -1;
        return reached[rsize-1][csize-1];

        
        
    }
};
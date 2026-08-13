class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int rows[]={0,-1,0,1};
        int cols[]={-1,0,1,0};
        int rsize = grid.size();
        int csize = grid[0].size();
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>reached( rsize , vector<int>( csize , INT_MAX));
        reached[0][0]=grid[0][0];
        pq.push( {grid[0][0],{0,0}});

        while(!pq.empty())
        {
            int power = pq.top().first;
            int r1 = pq.top().second.first;
            int c1 = pq.top().second.second;
            pq.pop();

            if( reached[r1][c1] < power) continue;
            if(r1==rsize-1 && c1==csize-1) return power;

            for( int i=0; i<4;i++)
            {
                int nrow = r1 + rows[i];
                int ncol = c1+ cols[i];

                if(nrow >=0 && nrow < rsize && ncol >=0 && ncol <csize)
                {
                   int p=max(power,grid[nrow][ncol]);
                   if(p < reached[nrow][ncol])
                   {
                        reached[nrow][ncol]=p;
                        pq.push( {p, {nrow,ncol}});
                   }
                }
            }
        }
        return 0;
        
    }
};
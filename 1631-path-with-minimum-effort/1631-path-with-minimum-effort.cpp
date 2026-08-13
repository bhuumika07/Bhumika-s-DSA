class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int rows[]={-1,0,1,0};
        int cols[] ={0,-1,0,1};
        int rsize=heights.size();
        int csize=heights[0].size();
        vector<vector<int>>reached(rsize, vector<int>(csize,1e9));
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
        reached[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            int val = pq.top().first;
            int r1 = pq.top().second.first;
            int c1= pq.top().second.second;
            pq.pop();

            if(reached[r1][c1] < val ) continue;
            if( reached[rsize-1][csize-1] < val) return reached[rsize-1][csize-1];
            
            for( int i=0; i<4;i++)
            {
                int nrow = r1 + rows[i];
                int ncol = c1 + cols[i];

                if(nrow >= 0 && nrow <rsize && ncol >=0 && ncol <csize)
                {
                    int v = abs( heights[nrow][ncol] - heights[r1][c1]);
                    v=max(v,val);
                    if( reached[nrow][ncol] > v )
                    {
                        reached[nrow][ncol]=v;
                        pq.push( {v , {nrow,ncol}});
                    }
                }
            }
        }
        if( reached[rsize-1][csize-1] == 1e9) return 0;
        return reached[rsize-1][csize-1];
        
    }
};
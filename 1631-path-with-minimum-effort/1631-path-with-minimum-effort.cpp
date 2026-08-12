class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int rows[]={-1,0,1,0};
        int cols[]={0,-1,0,1};
        int rsize = heights.size();
        int csize = heights[0].size();
        int mini=INT_MAX;
        priority_queue< pair<int, pair<int,int> > , vector<pair<int,pair<int,int>>> , greater<pair<int , pair<int,int>>>>pq;
        pq.push( {0, {0,0}});
        vector<vector<int>>visited(rsize, vector<int>(csize, INT_MAX));
        visited[0][0] = 0;
        while(!pq.empty())
        {
            int val = pq.top().first;
            int r1 = pq.top().second.first;
            int c1= pq.top().second.second;
            pq.pop();
            for( int i=0; i<4;i++)
            {
                int nrow = r1 + rows[i];
                int ncol = c1+ cols[i];

                if( nrow>=0 && nrow<rsize && ncol >=0 && ncol < csize &&visited[nrow][ncol] >  abs( heights[nrow][ncol] - heights[r1][c1]))
                {
                    visited[nrow][ncol]=abs( heights[nrow][ncol] - heights[r1][c1]);
                    int v = abs( heights[nrow][ncol] - heights[r1][c1]);
                    v=max( v,val);
                    pq.push({v,{nrow,ncol}});
                    if( nrow == rsize-1 && ncol == csize-1) mini=min(mini,v);
                }
            }

        }
        if( mini ==INT_MAX) return 0;
        return mini;

        
        
    }
};
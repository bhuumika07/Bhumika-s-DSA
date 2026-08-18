class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
         int rsize= moveTime.size();
        int csize = moveTime[0].size();
        vector<vector<int>>reached( rsize , vector<int>( csize , INT_MAX));
        priority_queue< pair<int,pair<int,pair<int,int>>> , vector<pair<int,pair<int,pair<int,int>>>> , greater<pair<int,pair<int,pair<int,int>>>>>pq;
        int rows[]={0,-1,0,1};
        int cols[]={-1,0,1,0};
        bool one=1;
        int val=1;
        pq.push( {0,{1,{0,0}}});

        while(!pq.empty())
        {
            int time = pq.top().first;
            int stops = pq.top().second.first;
            int r1 = pq.top().second.second.first;
            int c1 = pq.top().second.second.second;
            pq.pop();
            if( stops%2!=0 ) {val=1;}
            else { val=2;}
            if(reached[r1][c1] < time) continue;
            for( int i=0; i<4; i++)
            {
                int nrow = r1 + rows[i];
                int ncol = c1 + cols[i];
              
                if( nrow >= 0 && nrow <rsize && ncol >=0 && ncol < csize)
                {
                    if( time >=  moveTime[nrow][ncol])
                    {
                        if( reached[nrow][ncol] > time+val)
                        {
                            reached[nrow][ncol]=time+val;
                            pq.push( {time+val, {stops+1,{nrow,ncol}}});
                        }
                    }
                    else
                    {
                       if( reached[nrow][ncol] > moveTime[nrow][ncol] + val)
                       {
                            reached[nrow][ncol]=moveTime[nrow][ncol] + val;
                            pq.push( {reached[nrow][ncol], {stops+1,{nrow,ncol}}});
                       }
                    }
                    
                }
            }

        }
        return reached[rsize-1][csize-1];
        
        
    }
};
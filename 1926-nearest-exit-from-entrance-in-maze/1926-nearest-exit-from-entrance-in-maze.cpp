class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rsize=maze.size();
        int csize=maze[0].size();
       
        queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{entrance[0] , entrance[1]}});

        int rows[]={0,-1,0,1};
        int cols[]={-1,0,1,0};

        while(!pq.empty())
        {
            int stops = pq.front().first;
            int r1 = pq.front().second.first;
            int c1 = pq.front().second.second;
            pq.pop();
            if( (r1==0 || c1==0 ||r1 == rsize-1 || c1 == csize-1) && (r1!= entrance[0] || c1 != entrance[1])) return stops;
            for( int i=0; i<4;i++)
            {
                int nrow = r1 + rows[i];
                int ncol = c1 + cols[i];

                if( nrow >= 0 && nrow < rsize && ncol >= 0 && ncol <csize && maze[nrow][ncol] != '+')
                {
                    pq.push( {stops+1,{nrow,ncol}});
                    maze[nrow][ncol]='+';
                }
            }
        }
        return -1;       

        
    }
};
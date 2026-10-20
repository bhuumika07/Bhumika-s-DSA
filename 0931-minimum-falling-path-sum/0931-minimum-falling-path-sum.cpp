class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        priority_queue< tuple<int,int,int> , vector< tuple<int,int,int> > , greater< tuple<int,int,int>>>pq;
        vector< vector<int>> visited( n , vector<int>( n , INT_MAX));
      
        for( int i=0; i<n;i++)
        {
            pq.push( {matrix[0][i] , 0 , i});
        }
        int cols[] ={ -1 , 0 , 1};
        int mini = INT_MAX;
        while(!pq.empty())
        {
            auto [ sum , r , c] = pq.top();
            pq.pop();
            if( r == n-1 ) mini = min( mini , sum);
            // now can move 3 directions
            for( int i= 0 ; i<3 ; i++)
            {
                int nr = 1 + r;
                int nc = cols[i] + c;
                if( nr >= n || nc >= n || nr < 0 || nc < 0) continue;
                if( sum + matrix[nr][nc] < visited[nr][nc])
                {
                   visited[nr][nc]= sum + matrix[nr][nc];
                   pq.push( {visited[nr][nc] , nr, nc});
                }
            }

        }
        return mini;
    }
};
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        priority_queue< tuple<int,int,int> , vector< tuple<int,int,int> > , greater< tuple<int,int,int>> > pq;
        vector< vector<int> > visited( matrix.size() , vector<int>(matrix.size() , INT_MAX));
        for(int i=0; i<matrix.size();i++)
        {
            pq.push({ 0,i ,matrix[0][i]});
            visited[0][i] = matrix[0][i];
        }
        int rows[]={1,1,1};
        int cols[]={-1,0,1};
        int mini = INT_MAX;
        while(!pq.empty())
        {
            auto [r , c , path] = pq.top();
            pq.pop();
            if( visited[r][c] < path )continue;
            if( r == matrix.size() - 1) mini = min( mini , path);
            for( int i=0; i<3;i++)
            {
                int nrow = r + rows[i];
                int ncol = c + cols[i];
                if(nrow >=0 && ncol >=0 && nrow < matrix.size() && ncol < matrix.size())
                {
                    if( visited[nrow][ncol] > path + matrix[nrow][ncol])
                    {
                        visited[nrow][ncol] = path + matrix[nrow][ncol];
                        pq.push( {nrow , ncol , visited[nrow][ncol]});
                    }
                }
            }
        }

       return mini;
        
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n , vector<int>(m,0));
        vector<vector<bool>>visited( n, vector<bool>(m,0));
        
        queue<pair<pair<int,int>, int>>q;
        for( int i=0; i<n;i++)
        {
            for( int j=0; j<m;j++)
            {
                if( mat[i][j] == 0) 
                {
                    q.push( {{i,j} , 0});
                }
            }
        }
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        while( !q.empty())
        {
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int dis = it.second;

            for( int i=0; i<4; i++)
            {
                int nrow = delrow[i]+r;
                int ncol=delcol[i]+c;

                if( nrow >=0 && nrow < n && ncol >=0 && ncol < m && !visited[nrow][ncol] && mat[nrow][ncol] != 0)
                {
                    visited[nrow][ncol]=1;
                    ans[nrow][ncol]=dis+1;
                    q.push({{nrow,ncol} , dis+1});
                    // break;
                }
            }

           


        }
        return ans;
        
    }
};
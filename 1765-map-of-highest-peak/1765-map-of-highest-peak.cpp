class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n= isWater.size();
        int m= isWater[0].size();
        vector<vector<int>>ans( n , vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        vector<vector<bool>>visited(n , vector<bool>(m , 0));

        for( int i=0; i<n;i++)
        {
            for( int j=0; j<m; j++)
            {
                if(isWater[i][j] == 1) q.push( {{i,j},0});   
            }
        }

        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        while( !q.empty())
        {
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c= it.first.second;
            int dis = it.second;

            for( int i=0; i<4;i++)
            {
                int nrow = r + delrow[i];
                int ncol= c + delcol[i];

                if( nrow >=0 && nrow <n && ncol >=0 && ncol <m && !visited[nrow][ncol] && isWater[nrow][ncol] != 1)
                {
                    visited[nrow][ncol]=1;
                    ans[nrow][ncol]=dis+1;
                    q.push( {{nrow,ncol}, dis+1});
                }
            }
        }
        return ans;
        
    }
};
class Solution {
public:
    void bfs( int row , int col , vector<vector<bool>>&visited , vector<vector<int>>& land, vector<vector<int>>&ans)
    {
        int n=land.size();
        int m= land[0].size();
        int topr=n;
        int topc=m;
        int bottomr=0;
        int bottomc=0;

        queue<pair<int,int>>q;
        q.push({row,col});
        visited[row][col]=1;

        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};

        while(!q.empty())
        {
            auto it = q.front();
            int r = it.first;
            int c =it.second;
            q.pop();
            
            if( topr > r)
            {
                topr=r;
                topc=c;
            }
            else if( topr == r && topc > c)
            {
                topc=c;
            }

            if( bottomr < r)
            {
                bottomr= r;
                bottomc=c;
            }
            else if( bottomr == r && bottomc < c)
            {
                bottomc=c;
            }

            for( int i=0;i<4;i++)
            {
                int nrow= r+delrow[i];
                int ncol=c+delcol[i];

                if(nrow >=0 && nrow <n && ncol >=0 && ncol <m && !visited[nrow][ncol] &&land[nrow][ncol]==1)
                {
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }


        }
        ans.push_back( {topr,topc,bottomr,bottomc});

    

    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m= land[0].size();
        vector<vector<bool>>visited( n , vector<bool>(m,false));
        vector<vector<int>> ans;
        for( int i=0; i<n;i++)
        {
            for( int j=0;j<m;j++)
            {
                if(!visited[i][j] && land[i][j])
                {
                    bfs(i,j,visited,land,ans);
                }
            }
        }
        return ans;
        
    }
};
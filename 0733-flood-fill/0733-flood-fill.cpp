class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int first = image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        
        image[sr][sc]=color;
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        int n=image.size();
        int m= image[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[sr][sc]=1;
        while( !q.empty() )
        {
            auto pixel = q.front();
            q.pop();
            int r = pixel.first;
            int c= pixel.second;
            for( int i=0; i<4;i++)
            {
                int nrow = r+ drow[i];
                int ncol= c+ dcol[i];
                if( nrow >=0 && nrow <n && ncol>=0 && ncol <m && image[nrow][ncol]==first && !visited[nrow][ncol])
                {
                    visited[nrow][ncol]=1;
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
        
    }
};
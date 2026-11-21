class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int rows[] = { -1,0 ,1 ,0};
        int cols[] = { 0,-1,0,1};

        int org = image[sr][sc];

        if(org == color) return image;
        queue< pair<int,int> > q;
        q.push({sr,sc});
        image[sr][sc] = color;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            for( int i=0; i<4; i++){
                int nr = r + rows[i];
                int nc = c + cols[i];

                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if(image[nr][nc] != org) continue;
                image[nr][nc] = color;
                q.push({nr,nc});
            }
        }

        return image;
        
    }
};
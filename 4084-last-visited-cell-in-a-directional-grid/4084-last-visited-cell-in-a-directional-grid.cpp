class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int lastr = -1;
        int lastc = -1;
        int n = grid.size();
        int m = grid[0].size();
        vector< vector<bool> > visited( n , vector<bool>( m , 0));
        
       queue< pair<int,int> > q;
       q.push( {0,0});
       
       while(!q.empty())
       {
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            if( r < 0 || c < 0 || r >= n || c >= m) return {lastr , lastc};
            if( visited[r][c] ) return {lastr , lastc};
            visited[r][c] = 1;
            if( grid[r][c] == 'L') q.push( {r , c-1});
            else if( grid[r][c] == 'R') q.push( {r,c+1});
            else if( grid[r][c] == 'U') q.push( {r-1 , c});
            else q.push( { r+1, c});
            lastr = r;
            lastc = c;
       }
       return {lastr , lastc};
        
    }
};
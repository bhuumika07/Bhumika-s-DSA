class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int lastr = -1;
        int lastc = -1;
        int n = grid.size();
        int m = grid[0].size();
        vector< vector<bool> > visited( n , vector<bool>( m , 0));
        int currR = 0 ; int currC = 0;
        int r  = 0; int c = 0;
        while( currR >= 0 && currC>=0 && currR < n && currC < m)
        {
            if( visited[currR][currC]) return {lastr , lastc};
            if( grid[currR][currC] == 'L') { r = currR ; c = currC - 1;}
            else if( grid[currR][currC] == 'R') {r = currR; c = currC + 1;}
            else if( grid[currR][currC] == 'U') {r = currR - 1; c = currC;}
            else { r = currR+1 ; c = currC;}
            lastr = currR;
            lastc = currC;
            visited[currR][currC] = 1;
            currR = r;
            currC = c;
        }
       
       return {lastr , lastc};
        
    }
};
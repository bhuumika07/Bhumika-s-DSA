class Disjoint
{
    public:
    vector<int>parent;
    vector<int>size;
    Disjoint( int n)
    {
        parent.resize(n);
        size.resize(n,1);
        for( int i=0; i<n;i++) parent[i]=i;
    }
    int findParent( int node )
    {
        if( node == parent[node]) return node;
        return parent[node]= findParent( parent[node]);
    }
    void unionBysize( int a, int  b)
    {
        int ulp_a = findParent(a);
        int ulp_b = findParent(b);
        if( ulp_a == ulp_b) return;
        int size1 = size[ulp_a];
        int size2 = size[ulp_b];
        if( size1 < size2)
        {
            size[ulp_b]+=size[ulp_a];
            parent[ulp_a] = parent[ulp_b];
        }
        else
        {
            size[ulp_a]+=size[ulp_b];
            parent[ulp_b]=parent[ulp_a];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        Disjoint dj(n*n);
        int rows[]={0,-1,1,0};
        int cols[]={-1,0,0,1};
        for( int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if( grid[i][j]==0) continue;

                int node = i*n + j;
                for( int k=0;k<4;k++)
                {
                    int nrow = i + rows[k];
                    int ncol = j+ cols[k];
                    if( nrow >=0 && nrow <n && ncol >=0 && ncol <n && grid[nrow][ncol] == 1)
                    {
                        int neighbor = nrow*n + ncol;
                        dj.unionBysize(node , neighbor);
                    }
                }
            }
        }
         int ans = 0;

        // Step 2: Try converting every 0 into 1
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 1)
                    continue;

                set<int> components;

                for (int k = 0; k < 4; k++) {

                    int nr = r + rows[k];
                    int nc = c + cols[k];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        int neighbor = nr * n + nc;

                        components.insert(dj.findParent(neighbor));
                    }
                }

                int currentSize = 1;

                for (int parent : components) {
                    currentSize += dj.size[parent];
                }

                ans = max(ans, currentSize);
            }
        }

        // Handles the case where there is no 0
        for (int i = 0; i < n * n; i++) {
            if (dj.findParent(i) == i)
                ans = max(ans, dj.size[i]);
        }

        return ans;
        
    }
};
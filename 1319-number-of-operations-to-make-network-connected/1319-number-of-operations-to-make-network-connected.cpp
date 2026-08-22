class Disjoint
{
    public:
    vector<int>parent;
    vector<int>size;
    Disjoint( int n)
    {
        parent.resize(n);
        size.resize(n,1);
        for( int i=0; i<n; i++) parent[i]=i;
    }
    int findParent( int node)
    {
        if( node == parent[node]) return node;
        return parent[node] = findParent( parent[node]);
    }
    void unionBysize( int a, int b)
    {
        int ulp_a = findParent(a);
        int ulp_b = findParent(b);
        if( ulp_a == ulp_b) return;
        int size_a = size[ulp_a];
        int size_b = size[ulp_b];
        if( size_a < size_b)
        {
            parent[ulp_a]=ulp_b;
            size[ulp_b] +=size_a;
        }
        else if( size_b <= size_a)
        {
            parent[ulp_b]=ulp_a;
            size[ulp_a]+=size_b;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size();
        if( size < n-1) return -1;

        // if we were to find the connected component-- every node of connected component will have the same parent.

        Disjoint dj(n);

        for( int i=0; i<connections.size(); i++)
        {
            dj.unionBysize( connections[i][0] , connections[i][1]);
        }
        unordered_set<int>put;
        for( int i=0; i<n;i++)
        {
            int p = dj.findParent(i);
            put.insert(p);
        }
        
        return put.size()-1;

        
    }
};
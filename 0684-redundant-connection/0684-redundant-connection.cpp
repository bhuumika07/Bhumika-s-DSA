class Disjoint{
    public:
    vector<int>size;
    vector<int>parent;
    Disjoint( int n)
    {
        size.resize(n+1 , 1);
        parent.resize(n+1);
        for( int i=1; i<=n;i++) parent[i]=i;
    }
    int findParent( int node)
    {
        if( node == parent[node]) return node;
        return parent[node]= findParent( parent[node] );
    }

    void unionBySize( int a , int b)
    {
        int ulp_a = findParent(a);
        int ulp_b = findParent(b);
        if( ulp_a == ulp_b ) return;
        int sizea = size[ulp_a];
        int sizeb = size[ulp_b];
        if( sizea < sizeb)
        {
            parent[ ulp_a] = ulp_b;
            sizeb+=sizea;
        }
        else if( sizeb <= sizea)
        {
            parent[ulp_b] = ulp_a;
            sizea+=sizeb;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Disjoint dj(n);
        for( int i=0; i<n;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            if( dj.findParent(u) == dj.findParent(v)) return {u,v};
            dj.unionBySize(u,v);
        }
        return {};
        
    }
};
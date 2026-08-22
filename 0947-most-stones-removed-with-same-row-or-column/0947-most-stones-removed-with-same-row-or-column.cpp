class Disjoint{
    public:
    vector<int>size;
    vector<int>parent;
    Disjoint( int n)
    {
        size.resize(n,0);
        parent.resize(n);
        for( int i=0; i<n;i++) parent[i]=i;
    }
    int findParent( int node)
    {
        if( node == parent[node]) return node;
        return parent[node] = findParent( parent[node]);
    }
    void unionBysize( int a , int b )
    {
        int ulp_a = findParent(a);
        int ulp_b = findParent(b);
        if( ulp_a == ulp_b) return;
        if(size[ulp_a] == 0) size[ulp_a]=1;
        if( size[ulp_b] == 0) size[ulp_b]=1;
        int size1 = size[ ulp_a ];
        int size2 = size[ ulp_b ];
        
        if( size1 < size2)
        {
            parent[ulp_a] = parent[ulp_b];
            size[ulp_b] += size[ulp_a];
        }
        else
        {
            parent[ulp_b] = parent[ulp_a];
            size[ulp_a] += size[ulp_b]; 
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
       int OFFSET = 10001;
       Disjoint ds(20002);

       unordered_set<int>nodes;

       for( int i=0; i<stones.size(); i++)
       {
            int a = stones[i][0];
            int b= stones[i][1] + OFFSET;
            ds.unionBysize(a,b);
            nodes.insert(a);
            nodes.insert(b);
       }

       int comps=0;
       for( auto x : nodes)
       {
         if( x == ds.findParent(x)) comps++;
       }

       return stones.size() - comps;
        
    }
};
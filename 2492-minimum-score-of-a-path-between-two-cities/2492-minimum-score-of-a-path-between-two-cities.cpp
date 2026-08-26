class Disjoint
{
    public:
    vector<int>size;
    vector<int>parent;
    Disjoint( int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=1; i<=n;i++) parent[i]=i;
    }
    int findParent( int node)
    {
        if( node == parent[node]) return node;
        return parent[node]= findParent( parent[node] );
    }

    void unionBysize( int a , int b)
    {
        int ulp_a = findParent(a);
        int ulp_b = findParent(b);
        if( ulp_a == ulp_b) return;
        int size1=size[ulp_a];
        int size2=size[ulp_b];
        if( size1 < size2)
        {
            size[ulp_b]+=size[ulp_a];
            parent[ulp_a]=ulp_b;
        }
        else
        {
            size[ulp_a]+=size[ulp_b];
            parent[ulp_b] = ulp_a;
        }
    }


};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        Disjoint dj(n);
        for( int i=0;i<roads.size();i++)
        {
           dj.unionBysize(roads[i][0] , roads[i][1]); 
        }

        int ans =INT_MAX;

        for( int i = 0; i<roads.size();i++)
        {
            if( dj.findParent(roads[i][0]) == dj.findParent(1)) ans= min( ans , roads[i][2]);
        }
    
        return ans;
        
    }
};
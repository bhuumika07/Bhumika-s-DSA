class Alice
{
    public:
    vector<int>size;
    vector<int>parent;
    Alice( int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        for( int i=1; i<=n; i++) parent[i]=i;
    }
    int findParent( int node)
    {
        if( node == parent[node]) return node;
        return parent[node]=findParent( parent[node] );
    }
    bool unionBysize( int a , int b)
    {
        int ulp_a = findParent(a);
        int ulp_b = findParent(b);
        if( ulp_a == ulp_b) return 0;
        int size1 = size[ulp_a];
        int size2 = size[ulp_b];
        if( size1 < size2 )
        {
            size[ulp_b]+=size[ulp_a];
            parent[ulp_a]= parent[ulp_b];
        }
        else
        {
            size[ulp_a]+=size[ulp_b];
            parent[ulp_b]=parent[ulp_a];
        }
        return 1;
    }
};


class Bob
{
    public:
    vector<int>size;
    vector<int>parent;
    Bob( int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        for( int i=1; i<=n; i++) parent[i]=i;
    }
    int findParent( int node)
    {
        if( node == parent[node]) return node;
        return parent[node]=findParent( parent[node] );
    }
    bool unionBysize( int a , int b)
    {
        int ulp_a = findParent(a);
        int ulp_b = findParent(b);
        if( ulp_a == ulp_b) return 0;
        int size1 = size[ulp_a];
        int size2 = size[ulp_b];
        if( size1 < size2 )
        {
            size[ulp_b]+=size[ulp_a];
            parent[ulp_a]= parent[ulp_b];
        }
        else
        {
            size[ulp_a]+=size[ulp_b];
            parent[ulp_b]=parent[ulp_a];
        }
        return 1;
    }
};


class Solution {
public:

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        Alice ad(n);
        Bob bd(n);
        int count=0;
       sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) 
       {
        return a[0] > b[0];
        }
        );
        for( int i=0; i<edges.size();i++)
        {
            int type = edges[i][0];
            int u = edges[i][1];
            int v=edges[i][2];

            if( type == 1)
            {
                if(!ad.unionBysize(u,v)) count++;
            }
            else if( type == 2)
            {
                if(!bd.unionBysize(u,v)) count++;
            }
            else
            {
                bool ver1 = ad.unionBysize(u,v);
                bool ver2 = bd.unionBysize(u,v);
                if(!ver1&&!ver2) count++;
            }
        }
        int first=ad.findParent(1);
        int second=bd.findParent(1);
        for( int i=2; i<=n;i++)
        {
           int check = ad.findParent(i);
           if( check != first ) return -1;
           int check2 = bd.findParent(i);
           if( check2 != second) return -1;
        }

        return count;
    }
};
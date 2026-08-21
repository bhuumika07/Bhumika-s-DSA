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

    bool unionBySize( int a , int b)
    {
        int ulp_a = findParent(a);
        int ulp_b = findParent(b);
        if( ulp_a == ulp_b ) return 0;
        int sizea = size[ulp_a];
        int sizeb = size[ulp_b];
        if( sizea < sizeb)
        {
            size[ulp_b]+=size[ulp_a];
            parent[ ulp_a] = ulp_b;    
        }
        else if( sizeb <= sizea)
        {
            size[ulp_a]+=size[ulp_b];
            parent[ulp_b] = ulp_a;  
        }
        return 1;
    }
};
class Solution {
public:
     vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges){
        int n = edges.size();
      
        vector<int>parent(n+1,-1);
        int first=-1;
        int second=-1;
        for( int i=0; i<edges.size(); i++)
        {
            
            int v = edges[i][1];

            if( parent[v] != -1)
            {
                first = parent[v];
                second=i;
                break;
            }
            parent[v]=i;
        }
          Disjoint dj(n);

          for( int i=0; i<edges.size();i++)
          {
            if( i == second ) continue;
            
            int u = edges[i][0];
            int v = edges[i][1];

            if(!dj.unionBySize( u , v))
            {
                if( first != -1 ) return edges[first];

                return edges[i];
            }
          }

          return edges[second];



        

        
        
    }
};


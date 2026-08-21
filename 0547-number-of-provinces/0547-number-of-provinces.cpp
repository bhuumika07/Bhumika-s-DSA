class Solution {
public:
class DisjointSet
{
    public:

    vector<int>Parent;
    vector<int>size;
    
    DisjointSet( int n)
    {
        Parent.resize(n);
        size.resize(n,1);
        for( int i=0; i<n;i++) Parent[i]=i;
    }
    int findParent( int node)
    {
        if( node == Parent[node]) return node;
        return Parent[node]=findParent(Parent[node]);
    }
    void UnionBySize( int a , int b)
    {
        int ulp_a = findParent(a);
        int ulp_b = findParent(b);
        if( ulp_a == ulp_b) return;
        int sizea = size[ulp_a];
        int sizeb = size[ulp_b];
        if( sizea < sizeb)
        {
            Parent[ulp_a] = ulp_b;
            size[ulp_b]+=size[ulp_a];
        }
        else if( sizeb < sizea)
        {
            Parent[ulp_b]=ulp_a;
            size[ulp_a]+=size[ulp_b];
        }
        else
        {
            Parent[ulp_a] = ulp_b;
            size[ulp_b]+=size[ulp_a];
        }

    }
};
    int findCircleNum(vector<vector<int>>& given) {
        DisjointSet ds(given.size());
        for( int i=0; i<given.size();i++)
        {
            for( int j=0; j<given[0].size();j++)
            {
                if( given[i][j] == 1) ds.UnionBySize(i,j);
            }
        }
        int count=0;
        
        vector<int>temp;
        temp=ds.Parent;
    
        for( int i=0; i<temp.size(); i++)
        {
            if( i == ds.findParent(i))
            {
                count++;
            }
        }
        return count;

        
    }
};
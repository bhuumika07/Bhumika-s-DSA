class Disjoint{
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
        return parent[node] = findParent(parent[node]);
    }
    void unionBysize( int a , int b)
    {
        int ulp_a = findParent(a);
        int ulp_b = findParent(b);
        if( ulp_a == ulp_b) return;
        int size1 = size[ ulp_a ];
        int size2 = size[ulp_b];
        if( size1 < size2 )
        {
            parent[ ulp_a] = ulp_b;
            size[ulp_b] += size[ulp_a];
        } 
        else
        {
            parent[ ulp_b] = ulp_a;
            size[ulp_a] += size[ulp_b];
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        unordered_map<char,int>assign;
        Disjoint dj(26);
        int j=0;
        for( int i=0; i<equations.size();i++)
        {
            string s = equations[i];
            if( assign.find(s[0]) == assign.end() )
            {
                assign[s[0]]=j;
                j++;
            }
            if( assign.find( s[3]) == assign.end())
            {
                assign[s[3]] =j;
                j++;
            }

            int n1 = assign[s[0]];
            int n2 = assign[s[3]];
            if( s[1] == '=') dj.unionBysize( n1, n2);
        }
        for( int i=0; i<equations.size(); i++)
        {
            string s = equations[i];
            if( s[1] != '!') continue;

            int n1 = assign[s[0]];
            int n2 = assign[s[3]];

            if( dj.findParent(n1) == dj.findParent(n2)) return 0;
        }
        return 1;
    }
};
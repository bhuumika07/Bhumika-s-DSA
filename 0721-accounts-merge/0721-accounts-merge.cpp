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
        return parent[node] = findParent( parent[node]);
    }
    void unionBysize( int a , int b)
    {
        int ulp_a = findParent(a);
        int ulp_b = findParent(b);

        if( ulp_a == ulp_b) return;

        int size_a = size[ulp_a];
        int size_b = size[ulp_b];
        if( size_a < size_b)
        {
            parent[ulp_a] = parent[ulp_b];
            size[ulp_b] +=size_a;
        }
        else
        {
            parent[ulp_b] = parent[ulp_a];
            size[ulp_a]+=size_b;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // unordered_map<string , int > names;
        Disjoint dj( 10000 );
        unordered_map< string , int > mail;
        int k = 0;
       for (int i = 0; i < accounts.size(); i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
            // Register this email if it is new
            if (mail.find(accounts[i][j]) == mail.end())
            {
                mail[accounts[i][j]] = k++;
            }

            // Connect it with the previous email
            if (j > 1)
            {
                int a = mail[accounts[i][j - 1]];
                int b = mail[accounts[i][j]];

                dj.unionBysize(a, b);
            }
            }
        }
        unordered_map<int,set<string>>children;
        unordered_map<int , string >names;
        for( int i =0 ;i<accounts.size(); i++)
        {
            for( int j=1; j<accounts[i].size();j++)
            {
                int child = mail[accounts[i][j]];
                int parent = dj.findParent(child);
                children[parent].insert(accounts[i][j]);
                names[parent] = accounts[i][0];
            }
        }
        vector<vector<string>>ans( names.size());
        int j=0;
        for( auto it : names )
        {
            if( children[it.first].empty()) continue;
            ans[j].push_back( it.second );
            set<string>temp = children[it.first];
            ans[j].insert(ans[j].end(), temp.begin(), temp.end());
            j++;
        }
        return ans;



    
        
    }
};
class Solution {
public:
    void dfs( int node , vector<vector<int>>&adj , vector<bool>&visited , int& total)
    {
        visited[node]=1;
        total++;
        for( auto it : adj[node])
        {
            if(!visited[it])
            {
                dfs(it, adj,visited,total);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans=0;
      
        // building a adj matrix
        vector<vector<int>>adj(n);
        for( int i=0; i<edges.size();i++)
        {
            int u = edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }  
        vector<bool>visited(n,false);
        for( int i=0; i<n;i++)
        {
            if(!visited[i])
            {
                int total=0;
                dfs(i,adj,visited,total);
                int left = n-total;
                ans+=( 1LL*left*total);
            }               
        }

        return ans/2;
    }
};
class Solution {
public:
    void dfs( int src , int node , vector<vector<int>>&adj , vector<bool>&visited , vector<vector<int>>&ans)
    {
        visited[node]=1;
        if( src != node) ans[node].push_back( src );

        for( auto it : adj[node])
        {
            if(!visited[it]) dfs( src , it , adj , visited , ans);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for( int i=0; i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<vector<int>>ans(n);
        for( int i=0; i<n;i++)
        {
            vector<bool>visited(n);
            dfs( i , i , adj , visited , ans);
        }
        return ans;
        
    }
};
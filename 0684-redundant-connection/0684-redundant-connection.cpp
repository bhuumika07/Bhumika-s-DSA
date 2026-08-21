class Solution {
public:
    bool bfs( int node , int target ,vector<vector<int>>&adj , int n)
    {
        vector<bool>visited(n+1,0);
        queue<int>q;
        q.push(node);
        visited[node]=1;

        while(!q.empty())
        {
            int start = q.front();
            q.pop();
            if( start == target) return 1;
            for( auto it : adj[start])
            {
                if(!visited[it])
                {
                    visited[it]=1;
                    q.push( it );
                }
            }
        }
        return 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        for(int i=0; i<n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            if( bfs(u,v,adj,n)) return {u,v};

            adj[u].push_back(v);
            adj[v].push_back(u);
        
        }
        return {};
    }
};
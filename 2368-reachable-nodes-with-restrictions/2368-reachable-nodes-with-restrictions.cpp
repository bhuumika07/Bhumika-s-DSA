class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int>check;
        for( int i=0; i<restricted.size();i++) check.insert(restricted[i]);
        vector<vector<int>>adj(n);
        for( int i=0; i<edges.size();i++)
        {
            adj[ edges[i][0]].push_back( edges[i][1]);
            adj[ edges[i][1]].push_back( edges[i][0]);
        }
        queue<int>q;
        q.push(0);
        vector<bool>visited(n,0);
        visited[0]=1;
        int count=1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for( auto it : adj[node])
            {
                if(check.find(it)==check.end() && !visited[it])
                {
                    visited[it]=1;
                    count++;
                    q.push(it);
                }
            }
        }
        return count;
        
    }
};
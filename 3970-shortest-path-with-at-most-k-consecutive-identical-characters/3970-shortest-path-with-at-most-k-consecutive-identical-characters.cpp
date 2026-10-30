class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0; i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
        }
        // from a node -> traverse to every node its adjacent to and return the minimum cost and keep in mind that the characters should not be same more than k times along the path.
        // statees that i will be carrying in my pq -> node : weight : how many times i have seen it before [character]
        priority_queue< tuple<long long,int,int> , vector< tuple<long long,int,int>>, greater< tuple<long long,int,int>>>pq;
        vector<vector<long long>>visited(n , vector<long long>(k+1, INT_MAX));
        pq.push({0,0,1});
        visited[0][1] = 0;
        
        while(!pq.empty())
        {
            auto [weight ,node , freq] = pq.top();
            pq.pop();
            if(node == n-1) return weight;
            for(auto it : adj[node])
            {
                int f = 1;
                if(labels[it.first] == labels[node]) if(freq+1 <= k) f = freq+1; else continue;
                if( visited[it.first][f] > weight + it.second)
                    {pq.push({ weight + it.second,it.first , f});
                    visited[it.first][f] = weight + it.second;}
            }
        }
        return -1;
    }
};
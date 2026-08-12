class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start_node, int end_node) {
        // will make an adjancey list.
        vector<vector<pair<int,double>>>adj(n);
        for( int i=0; i<edges.size();i++)
        {
            adj[edges[i][0]].push_back( {edges[i][1], succ[i]} );
            adj[edges[i][1]].push_back( {edges[i][0], succ[i]} );
        }
        vector<double>dis(n,0.0);
        dis[start_node]=1.0;
        priority_queue<pair<double,int>>pq;
        pq.push( {1.0,start_node});

        while(!pq.empty())
        {
            int node = pq.top().second;
            double dist =pq.top().first;
            pq.pop();
            for( auto it : adj[node])
            {
                if( dis[it.first] < dist*it.second)
                {
                    dis[it.first] = dist*it.second;
                    pq.push({ dis[it.first] , it.first});
                }
            }
        }
        return dis[end_node];
    }
};
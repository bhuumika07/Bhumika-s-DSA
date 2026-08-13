class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for( int i=0; i<flights.size();i++)
        {
            adj[ flights[i][0] ].push_back({flights[i][1] , flights[i][2]});
        }
        vector<int>dist(n,INT_MAX);
        queue< pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        dist[src]=0;
        // k++;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if( stops > k) continue;
            for( auto i : adj[node])
            {
                int n = i.first;
                int d = i.second;
                if( dist[n] > cost + d && stops <=k)
                {
                    dist[n]=cost+d;
                    q.push( {stops+1, {n,dist[n]}});
                }
            }
        }
        if( dist[dst] == INT_MAX) return -1;
        return dist[dst];

        
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>>adj(n);
        for( int i=0; i<times.size();i++)
        {
            adj[times[i][0] - 1].push_back({times[i][1]-1 , times[i][2]});
        }
        vector<int>dist(n , INT_MAX);
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        pq.push( {0,k-1});
        dist[k-1]=0;

        while(!pq.empty())
        {
            auto info = pq.top();
            int dis = info.first;
            int node = info.second;
            pq.pop();
            for( auto it : adj[node])
            {
                int n = it.first;
                int d = it.second;
                if( dist[n] > d+dis)
                {
                    dist[n]=d+dis;
                    pq.push({dist[n] , n});
                }
            }
        }

        int maxi = INT_MIN;
        for( int i=0; i<n;i++)
        {
            if( dist[i] == INT_MAX) return -1;
            maxi=max( maxi , dist[i]);
        }
        return maxi;
        
    }
};
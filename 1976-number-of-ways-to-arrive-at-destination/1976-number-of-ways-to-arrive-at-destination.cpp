class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod =1e9+7;
        vector<vector<pair<int,int>>>adj(n);
        for( int i=0; i<roads.size();i++)
        {
            adj[roads[i][0]].push_back( {roads[i][1] , roads[i][2]});
            adj[roads[i][1]].push_back( {roads[i][0] , roads[i][2]});
        }
        vector<long long>dist(n,LONG_MAX);
        vector<long long>ways(n , 0);
        priority_queue< pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>>pq;
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty())
        {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if( dist[node] < dis) continue;
    
            for( auto it : adj[node])
            {
                int n1 = it.first;
                long long d = it.second;
                if( dist[n1] == d+dis) ways[n1]= (ways[n1]+ways[node])%mod;
                if(dist[n1] > d+dis)
                {
                    dist[n1]=d+dis;
                    ways[n1]=ways[node];
                    pq.push( {dist[n1] , n1});
                }  
            }
        }
        return ways[n-1];
    }
};
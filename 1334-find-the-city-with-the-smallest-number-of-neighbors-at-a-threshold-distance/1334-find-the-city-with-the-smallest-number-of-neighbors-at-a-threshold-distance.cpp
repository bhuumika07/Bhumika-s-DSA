class Solution {
public:
    int findit(int node , vector<vector<pair<int,int>>>&graph , int maxi )
    {
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        pq.push({0,node});
        vector<int> dist(graph.size(), INT_MAX);
        dist[node] = 0;
        int count=0;
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int n = pq.top().second;
            pq.pop();

            for( auto it : graph[n])
            {
                int n1 = it.first;
                int d1 = it.second;
                if(dis + d1 < dist[n1] && dis + d1 <= maxi)
                {
                    dist[n1] = dis + d1;
                    pq.push({dist[n1], n1});
                }
            }
        }
        for( int i=0; i<graph.size();i++)
        {
            if( i!= node && dist[i] <= maxi) count++;
        }
        return count;

    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        for( int i=0; i<edges.size();i++)
        {
            adj[ edges[i][0] ].push_back( {edges[i][1], edges[i][2]});
            adj[ edges[i][1] ].push_back( {edges[i][0], edges[i][2]});
        }
       
        int ans=0;
        int mini=INT_MAX;
        for( int i=0; i<n;i++)
        {
            int val = findit( i , adj , distanceThreshold);
            if( val < mini)
            {
                mini=val;
                ans=i;
            }
            else if( val == mini) 
            {
                mini=val;
                ans=max( ans , i);
            }
        }
        return ans;
        
    }
};
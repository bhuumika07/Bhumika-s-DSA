class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n =points.size();
        
        vector<bool>visited(n);

        priority_queue<
            pair<int,int>,
            vector< pair<int,int>> ,
            greater< pair<int,int>>
            >pq;

        pq.push({0,0});
        int sum=0;
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            int r = points[node][0];
            int c = points[node][1];
            pq.pop();
            if(visited[node]) continue;
            visited[node]=1;
            sum+=dis;
            for( int i=0; i<points.size();i++)
            {
                if(!visited[i])
                {
                    int d = abs(r - points[i][0]) + abs( c - points[i][1]);
                    pq.push({d,i});
                }
            }
        }
        return sum;
       
    }
};
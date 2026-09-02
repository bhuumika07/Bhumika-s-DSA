class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int mask = (1 << n) - 1;

        queue< tuple<int,int,int> > q;
        for( int i=0; i<n; i++)
        {
            q.push({i,0,1<<i});
        }
        vector< vector<bool>> visited( n , vector<bool>(1<<n , false));
        while(!q.empty())
        {
            auto [node , steps , counting] = q.front();
            q.pop();
            if( counting == mask) return steps;
            if(visited[node][counting]) continue;
            visited[node][counting]=1;
            for( auto it : graph[node])
            {
                int state = counting | 1 << it;
                if( visited[it][state]) continue;
                q.push({it,steps+1,state});
            }

        }
        return -1;

        
    }
};
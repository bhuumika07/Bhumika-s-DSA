class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int mask = (1 << n) - 1;
        vector< vector<bool>> visited( n , vector<bool>(1<<n , false));
        queue< tuple<int,int,int> > q;
        for( int i=0; i<n; i++)
        {
            q.push({i,0,1<<i});
            visited[i][1<<i]=1;
        }
      
        while(!q.empty())
        {
            auto [node , steps , counting] = q.front();
            q.pop();
            if( counting == mask) return steps;
            for( auto it : graph[node])
            {
                int state = counting | 1 << it;
                if( visited[it][state]) continue;
                q.push({it,steps+1,state});
                visited[it][state]=1;
            }

        }
        return -1;

        
    }
};
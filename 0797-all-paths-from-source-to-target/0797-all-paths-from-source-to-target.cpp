class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        queue<pair<vector<int>,int>> q;
        q.push({{0},0});
        int n=graph.size();
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            vector<int>temp=it.first;
            int node = it.second;
            if( node == n-1 ) ans.push_back( temp);
            for( auto i : graph[node])
            {
                temp.push_back(i);
                q.push({temp,i});
                temp.pop_back();
            }
        }
        return ans;
        
    }
};
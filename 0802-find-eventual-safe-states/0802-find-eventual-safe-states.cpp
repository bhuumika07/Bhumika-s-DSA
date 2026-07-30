class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // going to use the reverse the graph and implement kahn's algo
        int size = graph.size();
        vector<vector<int>>rev(size);
        vector<int>outdegree( size , 0);

        for( int i=0; i<size;i++)
        {
            outdegree[i]=graph[i].size();
            for(auto it : graph[i])
            {
                rev[it].push_back(i);
            }
        }

        // extracting terminal nodes
        queue<int>q;
        for( int i=0; i<size;i++)
        {
            if( outdegree[i] == 0) q.push(i);
        }

        vector<int>ans;
        while( !q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back( node );

            for( int i : rev[node])
            {
                outdegree[i]--;
                if (outdegree[i] == 0)
                    q.push(i);
            }
        }
        sort( ans.begin() , ans.end());
        return ans;
        
    }
};
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // another approach is topological sort
        vector<vector<int>>graph(n);
        vector<int>indegree(n,0);

        for( int i=0; i<edges.size();i++)
        {
            graph[ edges[i][0]].push_back( edges[i][1]);
            indegree[ edges[i][1] ]++;
        }

        queue<int>q;
        for( int i=0; i<n;i++)
        {
            if( indegree[i] == 0) q.push(i);
        }

        vector<set<int>>anc(n);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for( int i : graph[node])
            {
                anc[i].insert(node);

                for( auto it : anc[node])
                {
                    anc[i].insert(it);
                }
                indegree[i]--;

                if( indegree[i]==0) q.push(i);
            }
        }
       vector<vector<int>> ans;

        for (auto &st : anc)
        {
            ans.push_back(vector<int>(st.begin(), st.end()));
        }


        return ans;

        
    }
};
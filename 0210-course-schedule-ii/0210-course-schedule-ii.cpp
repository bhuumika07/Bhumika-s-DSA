class Solution {
public:
    vector<int>ans;
    bool dfs( int node , vector<vector<int>>&adj , vector<bool>&visited , vector<bool>&inPath)
    {
        visited[node]=1;
        inPath[node]=1;
       
        for( auto it : adj[node])
        {
            if( !visited[it] )
            {
                if( dfs(it , adj , visited, inPath)) return 1;
            }
            else if( inPath[it] ) return 1;
        }
        ans.push_back(node);
        inPath[node]=0;
        return 0;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>>adj(numCourses);
        for( int i=0; i<prerequisites.size(); i++)
        {
            int todo = prerequisites[i][0];
            int req = prerequisites[i][1];

            adj[todo].push_back(req);
        }

        vector<bool> visited(numCourses, false);
       vector<bool> inPath(numCourses, false);

        for( int i = 0; i<numCourses; i++)
        {
            if(!visited[i])
            {
                if( dfs(i , adj , visited , inPath) ) return {};
            }
        }
        return ans;
        
    }
};
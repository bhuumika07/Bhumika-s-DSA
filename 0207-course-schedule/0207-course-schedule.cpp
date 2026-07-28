class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>>adj(numCourses);
        for( int i=0; i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
            if( pre[i][0] == pre[i][1]) return 0;
        }
        queue<int>q;
        for( int i=0; i<numCourses;i++)
        {
            if( indegree[i] == 0 ) q.push(i);

        }
        if( q.empty() )return 0;
        int count=0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for( auto it : adj[node])
            {
                indegree[it]--;
                if( indegree[it] == 0) q.push(it);
            }
        }
        return count == numCourses;
        
    }
};
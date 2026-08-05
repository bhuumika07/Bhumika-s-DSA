class Solution {
public:
    void dfs( vector<int>&sus , vector<int>&indegree, vector<vector<int>>&graph, int node, vector<bool>&visited )
    {
        visited[node]=1;
        sus[node]=2;
        for( auto it : graph[node])
        {
          
          if( indegree[it] > 0) { 
             indegree[it]--;
             if( !visited[it])  dfs(sus,indegree,graph,it,visited);
             }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>sus(n,0);
        vector<int>indegree(n,0);
        vector<bool>visited(n,0);
        vector<vector<int>>graph(n);
        for( int i=0; i<invocations.size();i++)
        {
            graph[ invocations[i][0]].push_back( invocations[i][1]);
            indegree[invocations[i][1]]++;
        }
        // if(indegree[k] > 0) indegree[k]--;
        dfs(sus,indegree,graph,k, visited);
        bool check=1;
        for( int i=0; i<n;i++)
        {
            if( sus[i] == 2 && indegree[i] > 0) {check=0; break;}
        }
        vector<int>ans;
        if( check )
        {
            for( int i=0; i<n;i++)
            {
                if( sus[i]!=2) ans.push_back(i);
            }
        }
        else 
        {
            for( int i=0; i<n;i++) ans.push_back(i);
        }
        return ans;
        
    }
};
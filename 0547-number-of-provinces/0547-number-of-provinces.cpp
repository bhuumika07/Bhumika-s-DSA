class Solution {
public:
    void dfs( int node , vector<vector<int>>&adj , vector<bool>&visited , int &count)
    {
        if( !visited[node]) count++;
        visited[node]=1;
        for( auto it : adj[node])
        {
            if(!visited[it]) 
            {
                visited[it]=1;
                dfs( it , adj , visited , count);
            }
        }


    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>visited(isConnected.size(), false);
        int count=0;
        // will make an adjaceny list first.
        vector<vector<int>>adj;
        for( int i=0; i<isConnected.size();i++)
        {
            vector<int>related;
            for( int j=0; j<isConnected.size();j++)
            {
                if( i!=j && isConnected[i][j]) related.push_back(j);
            }
            adj.push_back(related);
        }
        int node=0;
        for( int i=0; i<adj.size();i++) dfs( i , adj , visited , count);
        return count;
    }
};
class Solution {
public:
    int dfs( int node , vector<vector<int>>&graph, vector<bool>&visited , vector<int>&quiet, int &bestPerson)
    {
       if (quiet[node] < quiet[bestPerson]) bestPerson = node;
        visited[node]=1;
        for( auto it : graph[node])
        {
            if(!visited[it]) 
            {
                dfs( it , graph , visited , quiet ,bestPerson);
            }
        }
        return bestPerson;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int size = quiet.size();
        vector<vector<int>>graph(size);
        for( int i=0; i<richer.size();i++)
        {
            graph[ richer[i][1] ].push_back( richer[i][0]);
        }
        vector<int>ans;
        for( int i=0; i<size;i++)
        {
            vector<bool>visited(size,false);
            int mini=i;
            int put = dfs( i , graph , visited, quiet, mini);
            ans.push_back(put);
        }
        return ans;
        
    }
};
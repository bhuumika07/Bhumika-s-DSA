class Solution {
public:
    bool dfs( int node , int col , vector<vector<int>>& graph, vector<int>&color)
    {
        color[node]=col;
        for( auto it : graph[node])
        {
            if( color[it] == -1)
            {
                if(dfs(it , !col , graph , color)==false) return false;
            }
            else if( col == color[it]) return 0;
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<int>color(size , -1);
        for( int i=0; i<size; i++)
        {
            if(color[i]==-1)
            {
                if(dfs( i , 0 , graph , color)== false) return 0;
            }
        }
        return 1;
        
    }
};
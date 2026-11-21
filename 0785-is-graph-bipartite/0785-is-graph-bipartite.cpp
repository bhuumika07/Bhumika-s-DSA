class Solution {
public:
    bool doit(vector<vector<int>>& graph, vector<int>&visited, int node){
        for( auto it : graph[node]){
            if(visited[it] != 0 && visited[it] == visited[node]) return 0;
            else if( !visited[it]){
                visited[it] = (visited[node] == 1) ? 2 : 1;
                if(!doit(graph,visited,it)) return 0;
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int last = 2;
        vector<int>visited(n,0);
        for( int i = 0; i<n;i++){
            if(visited[i]==0){
                visited[i] = (last == 1) ? 2 : 1;
                last = visited[i];
                if(!doit(graph,visited,i)) return 0;
                }
        }
        return 1;
        
    }
};
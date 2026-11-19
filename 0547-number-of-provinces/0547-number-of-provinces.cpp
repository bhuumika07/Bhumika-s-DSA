class Solution {
public:
    void visitit(vector<vector<int>>&adj , vector<bool>&visited , int node){
        for( auto it : adj[node]){
            if(!visited[it]){
                visited[it] = 1;
                visitit(adj,visited,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int  n = isConnected.size();
        vector<vector<int>>adj(n);
        for( int i = 0; i<n ; i++){
            for( int j=0; j<n; j++){
                if( i == j && isConnected[i][j]) continue;
                if(isConnected[i][j]) adj[i].push_back(j);
            }
        }

        vector<bool>visited( n , 0);
        int count = 0;
        for( int i = 0; i<n; i++){
            if(!visited[i]){
                count++;
                visited[i] = 1;
                visitit(adj,visited,i);
            }
        }
        return count;
    }
};
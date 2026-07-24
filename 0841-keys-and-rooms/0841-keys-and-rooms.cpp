class Solution {
public:
    void dfs( int room , int &count,  vector<bool>&visited , vector<vector<int>>& rooms)
    {
        visited[room]=1;
        for( auto it : rooms[room])
        {
            if(!visited[it])
            {
                count++;
                dfs( it , count , visited , rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();
        vector<bool>keys( size , 0);
        vector<bool>visited( size , 0);
        int count =0;
        count++;
        dfs( 0 , count , visited , rooms);
        return ( count == size);
        
    }
};
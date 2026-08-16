class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int total=requests[0];
        int curr=requests[0];
        for( int i=1; i<requests.size();i++)
        {
            total+=abs( requests[i] - requests[i-1]);
        }
        return total;
        
    }
};
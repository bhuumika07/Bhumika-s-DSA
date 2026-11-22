class Solution {
public:
    bool doit(vector<int>&arr , int index, vector<bool>&visited){
        if( index < 0 || index >= arr.size()) return 0;
        if( arr[index] == 0 ) return 1;
        if(visited[index] == 1) return 0;
        visited[index] = 1;
        return (doit(arr,index + arr[index],visited) || doit(arr, index-arr[index] , visited));
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool>visited(arr.size() , 0);
      return doit(arr,start,visited);

    }
};
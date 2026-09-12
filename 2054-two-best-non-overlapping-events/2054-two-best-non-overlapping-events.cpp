class Solution {
public:
    int dp[100005][3];
    int doit( vector<vector<int>>&events , int idx ,int val )
    {
        if( idx == events.size()) return 0;
        if( val  == 0) return 0;
        if( dp[idx][val] != -1) return dp[idx][val];
        int dont = doit( events , idx+1, val);
        int take = events[idx][2];
        int next = events.size();
        int low = idx+1 ; int high = events.size()-1;
        while( low <= high){
            int mid = low+( high-low)/2;
            if(events[mid][0] > events[idx][1])
            {
                next = mid;
                high = mid-1;
            } else low =mid+1;
        }
        take+=doit(events , next , val -1);

        return dp[idx][val]= max(take , dont);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        memset( dp , -1 , sizeof(dp));
        sort( events.begin() , events.end());
        return doit( events , 0 , 2);
        
    }
};
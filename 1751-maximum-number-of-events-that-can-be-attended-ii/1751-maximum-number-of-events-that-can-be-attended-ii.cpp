class Solution {
public:
    
    long long doit( vector<vector<int>>& events,int idx ,  int k , vector<vector<long long>>&dp)
    {
        if( k==0 || idx == events.size()) return 0;
        if(dp[idx][k] != -1) return dp[idx][k];
        // take me
        long long take = events[idx][2];
        int next = events.size();
        int low = idx+1; int high = events.size()-1;
        while( low <= high)
        {
            int mid = low+(high-low)/2;
            if( events[mid][0] > events[idx][1])
            {
                next = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        take+=doit(events,next,k-1 , dp);
        long long dont = doit( events , idx+1,k, dp);
        return dp[idx][k] = max( take , dont);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        vector<vector<long long>>dp(events.size() , vector<long long>(k+1,-1));

        sort(events.begin() , events.end());
        return doit( events , 0 , k , dp);
        
    }
};
class Solution {
public:
    long long dp[30005];
    long long doit( vector<vector<int>>&rides , int idx )
    {
        if(idx == rides.size()) return 0;
        if( dp[idx] != -1 ) return dp[idx];
        long long dont = doit(rides , idx+1);
        long long take = rides[idx][1] - rides[idx][0] + rides[idx][2];
        int next = rides.size();
        int low = idx+1; int high = rides.size()-1;
        while( low <= high)
        {
            int mid = low + (high-low)/2;
            if( rides[mid][0] >= rides[idx][1])
            {
                next = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        take += doit( rides , next);
        return dp[idx]=  max(take,dont);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        memset( dp ,-1 , sizeof(dp));
        sort(rides.begin() , rides.end());
        return doit(rides,0);

        
    }
};
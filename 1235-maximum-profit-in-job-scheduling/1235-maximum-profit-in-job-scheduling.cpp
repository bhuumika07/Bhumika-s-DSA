class Solution {
public:
    int dp[100005];
    long long doit( vector<vector<int>>& time, int idx )
    {
        if( idx == time.size()) return 0;
        // i will take this profit
        if(dp[idx] != -1) return dp[idx];
        long long take = time[idx][2];
        int next = time.size();
        int low = idx+1; int high = time.size()-1;
        while( low <= high)
        {
            int mid = low + ((high-low)/2);
            if(time[mid][0] >= time[idx][1])
            {
                next = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        take+=doit(time,next);
        long long donot = doit( time,idx+1);

        return dp[idx] = max(take,donot);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>time(n);
        for( int i=0; i<n;i++)
        {
            int u = startTime[i];
            int v = endTime[i];
            int p = profit[i];
            time[i] = {u,v,p} ;
        }
        sort( time.begin() , time.end());
        memset(dp,-1,sizeof(dp));
        return doit(time,  0);
        
    }
};
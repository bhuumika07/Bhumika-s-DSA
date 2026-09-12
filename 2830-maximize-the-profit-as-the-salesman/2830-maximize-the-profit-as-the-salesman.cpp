class Solution {
public:
    int dp[100005];
    int doit( vector<vector<int>>&offers , int idx)
    {
        if( idx == offers.size()) return 0;
        if( dp[idx] != -1) return dp[idx];
        int dont = doit( offers , idx+1);
        int take = offers[idx][2];
        int next = offers.size();
        int low = idx+1; int high = offers.size()-1;
        while( low <= high){
            int mid = low +( high-low)/2;
            if( offers[mid][0] > offers[idx][1])
            {
                next = mid;
                high =mid-1;
            }
            else low =mid+1;
        }
        take += doit( offers , next);

        return dp[idx] = max( take , dont);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        memset( dp , -1 , sizeof(dp));
        sort( offers.begin() , offers.end());
        return doit( offers , 0);
        
    }
};
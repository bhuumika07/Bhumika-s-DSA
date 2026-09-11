class Solution {
public:
    int dp[100005][13];
    int doit(vector<int>& coins, int amount , int idx , long long collected )
    {
        if( amount == collected ) return 0;
        if( collected > amount ) return INT_MAX;
        if(idx == coins.size()) return INT_MAX;
        if(dp[collected][idx] != -1 ) return dp[collected][idx];
        // since we can use the same index
        int takeSame = doit(coins , amount , idx , collected + coins[idx]);
        if (takeSame != INT_MAX) takeSame += 1;
        int goAhead = doit( coins , amount , idx+1 , collected );

        return dp[collected][idx] = min(takeSame ,  goAhead) ;
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        memset(dp,-1,sizeof(dp));
        int val = doit(coins , amount ,0,0) ;
        if( val == INT_MAX) return -1;
        return val;
    }
};
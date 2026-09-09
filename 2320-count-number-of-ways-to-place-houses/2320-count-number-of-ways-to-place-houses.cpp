class Solution {
public:
long long dp[10005];
long long  mod = 1e9 + 7;
    long long doit( int n , int idx)
    {
        if( idx < 1) return 1;
        // i am not going to place the house.
        if( dp[idx] != -1 ) return dp[idx];
        long long havenot = 0;
        if(idx-1 > 1 && dp[idx-1] != -1) havenot+=dp[idx-1];
        else havenot+=doit(n, idx-1);

        // i am going to place the house.
        long long have=0;
        if( idx-2 > 1 && dp[idx-2] != -1) have+=dp[idx-2];
        else have +=doit( n,idx-2);
        have = have%mod;
        havenot = havenot%mod;
        return dp[idx] = (have + havenot)%mod ;
    }
    int countHousePlacements(int n) {
        memset( dp , -1, sizeof(dp));
        long long val =doit( n , n);
        return (1LL*val*val)%mod;
    }
};
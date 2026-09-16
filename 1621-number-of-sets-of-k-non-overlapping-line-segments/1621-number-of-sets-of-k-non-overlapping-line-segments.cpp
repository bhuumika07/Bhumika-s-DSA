class Solution {
public:
    long long dp[1001][1000];
    
    int mod = 1e9 + 7;
    long long doit( int n , int idx , int k)
    {
        if( k == 0) return 1;
        if( idx ==  n-1) return 0;
        if( dp[idx][k] != -1 ) return dp[idx][k];
        long long take = 0;
        for( int i = idx +1 ; i<n; i++)
        {
            take += (doit( n , i , k-1 )) % mod;
        }
        long long dont = (doit( n , idx+1 , k))%mod;

        return dp[idx][k] = (take + dont)%mod;
    }
    int numberOfSets(int n, int k) {
        if( n == k+1) return 1;
        memset( dp , -1 , sizeof(dp));
        return doit( n , 0 , k);
        
    }
};
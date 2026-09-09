class Solution {
public:
    long long dp[100005];
    long long mod =1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,0,sizeof(dp));
        
        for( long long i =high ; i>=0; i--)
        {
            int val=0;
            if(i>=low && i<=high)val=1;

            dp[i] = val;
            if( i + zero <= high) dp[i]= (dp[i] + dp[i+zero])%mod;
            if( i + one <= high) dp[i]= (dp[i] +dp[i+one]) %mod;
        }
        return dp[0];
        
    }
};
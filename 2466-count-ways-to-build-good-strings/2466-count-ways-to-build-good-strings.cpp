class Solution {
public:
    int dp[100005];
    int mod =1e9 + 7;
    int doit( int low , int high , int a , int b , int ans)
    {
        if( ans > high ) return 0;
        int val=0;
        if( ans>= low &&  ans <= high) val=1; 
        // i will take option 1 i.e add zero
        int size1 = 0 ;
        if( ans+a <= high ) 
            if( dp[ans+a] != -1) size1 +=dp[ans+a];
            else size1+=doit(low , high , a,b , ans + a);
        // i will take option 2
        int size2 = 0;
        if( ans+b <= high)
            if(dp[ans+b] != -1) size2+=dp[ans+b];
            else size2+=doit( low , high ,a , b,ans+b);

        return dp[ans] =(size1 + size2 + val)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset( dp , -1 , sizeof(dp));
        return doit( low , high , zero , one, 0);
        
    }
};
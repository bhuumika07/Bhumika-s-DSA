class Solution {
public:
long long  mod = 1e9 + 7;
    int countHousePlacements(int n) {
        long long nn =1;
        long long n1 = 2;
        long long ans = 2;
        for( int i=2; i<=n;i++)
        {
            ans = (n1+nn) % mod;
            nn = n1;
            n1=ans;
        }
        return (ans*ans)%mod;
    }
};
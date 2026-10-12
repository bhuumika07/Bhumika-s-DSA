class Solution {
public:
    bool isprime( int num)
    {
        for( int i=2 ; i*i <= num ; i++)
        {
            if( num % i == 0) return 0;
        }
        return 1;
    }
    vector<int> maxPrimes(int n, int s) {
        long long sum = 0;
        vector<int>ans;
        for(int i = 2; i<=n ; i++)
        {
            if(isprime(i) && sum +i <= s)
            {
                sum+=i;
                ans.push_back(i);
            }
            if( sum + i > s) break;
        }
        return ans;
    }
};
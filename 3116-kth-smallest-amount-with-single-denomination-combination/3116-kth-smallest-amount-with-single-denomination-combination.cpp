class Solution {
public:
    long long behindme( long long mid , vector<int>&coins)
    {
        long long correctCount = 0;
        int n = coins.size();

        for( int expressions = 1; expressions< (1<<n); expressions++)
        {
            long long lcm=0;
            long long order=0;
            for( int i=0; i<n;i++)
            {
                if( expressions & (1 << i))
                {
                    order++; // we have taken the ith coin.

                    if( lcm == 0)
                    {
                        lcm = coins[i];
                    }
                    else{
                        lcm = lcm*coins[i] / gcd( lcm, coins[i]);
                    }
                }
            } 
            if( order%2 == 0) correctCount -=mid/lcm;
            else correctCount+=mid/lcm; 
        }
    return correctCount;
}
    long long findKthSmallest(vector<int>& coins, int k) {
      long long low = *min_element( coins.begin() , coins.end());
      long long high =(1LL)* (*max_element( coins.begin() , coins.end())) *k;
      long long result=-1;
      while( low <= high)
      {
        long long mid = low + ( high-low)/2;

        if( behindme( mid,coins ) >= k ) {result =mid;high = mid-1;}
        else low =mid+1;
      }
      return result;
    }
};
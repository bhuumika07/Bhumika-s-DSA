class Solution {
public:
    long long doit( vector<int>&piles, int eat){
        long long hours = 0;
        for(int i=0; i<piles.size();i++){
            if(piles[i] <= eat) hours++;
            else{
                hours+=( piles[i]/eat);
                if(piles[i]%eat != 0) hours++;
            }
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1; // she can eat 1 banana
        long long high =*max_element(piles.begin() , piles.end());
        long long ans = high;
        while( low <= high){
            long long mid = low + (high - low)/2;
            // mid gives me the number of bananas koko will eat in 1 hour.
            // i need to minimize the number of bananas eaten pr hour.
            // i will traverse for every value and check this spped takes how many hours.
            // if hours taken are greater than h --> then obv i need to increase the number of banans eaten.
            // if hours are less or equal i will try and minimize my value.
            long long time_taken = doit(piles , mid);
            if( time_taken <= h){
                ans=min(ans,mid);
                high =mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};
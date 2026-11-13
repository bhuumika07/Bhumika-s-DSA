class Solution {
public:
    long long check( vector<int>&time , long long speedLimit){
        long long trips = 0;
        for( int i=0; i<time.size(); i++){
            if(time[i] <= speedLimit){
                trips+=1LL*( speedLimit/time[i]);
            }
        } 
        return trips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        // i need to cover atleast totalTrips with minimum time.

        long long low = *min_element(time.begin() , time.end());
        long long high =1LL*(low * totalTrips);
        long long ans =-1;
        while( low <= high){
            long long mid = low + ( high - low)/2;
            long long trips_made = check( time , mid);
            if(trips_made < totalTrips) {low = mid+1;}
            else{
                ans = mid;
                 high =mid-1;
            }
        }
        return ans;
        
    }
};
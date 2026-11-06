class Solution {
public:
    int doit( vector<int>&weights , int cap){
        int days = 0;
        int curr  = 0;
        for(int i=0; i<weights.size();i++){
            if(weights[i] + curr <= cap) curr += weights[i];
            else{
                days++;
                if(weights[i] > cap) return -1;
                curr = weights[i];
            }
        }
        if( curr != 0) days++;
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // the minimum weight a ship can carry is the minimum element in weights.
        int low = *min_element( weights.begin() , weights.end() );
        int high = 0;
        for( int x : weights) high += x;
        int ans = -1;
        while( low <= high){
            int mid = low + ( high - low)/2;
            int daysNeeded = doit( weights, mid);
            if( daysNeeded == -1 || daysNeeded > days) low = mid + 1;
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};
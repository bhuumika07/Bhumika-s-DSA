class Solution {
public:
    long long doit(vector<int>&bloomDay , int waited , int k){
        long long collect = 0;
        long long adj = 0;
        for(int i=0; i<bloomDay.size();i++){
            if(bloomDay[i] <= waited){
                adj++;
            }else{
                if(adj >= k){
                    collect +=( adj/k);
                }
                adj=0;
            }
        }
        if(adj != 0){
           if(adj >= k){
                    collect +=( adj/k);
                } 
        }
        return collect;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long low = *min_element(bloomDay.begin() , bloomDay.end());
        long long high = *max_element(bloomDay.begin() , bloomDay.end());
        // i will calculate the waiting days and then try to make bouquets ->
        // if i succeed then i will try to minimize it further if possible.
       long long minDays = LLONG_MAX;
        while( low <= high){
            long long mid = low + ( high - low )/2;
            long long collect = doit(bloomDay , mid , k);
            if( 1LL*collect*k >= 1LL*m*k && collect >= m){
                minDays = min(minDays , mid);
                high=mid-1;
            }
            else low = mid+1;
        }   
        if(minDays == INT_MAX) return -1;
        return minDays;    
    }
};
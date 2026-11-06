class Solution {
public:
    int doit(vector<int>&bloomDay , int waited , int k){
        int collect = 0;
        int adj = 0;
        for(int i=0; i<bloomDay.size();i++){
            if(bloomDay[i] <= waited){
                adj++;
            }else{
                collect += (adj/k);
                adj=0;
            }
        }
        collect += adj/k;
        return collect;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if( 1LL*m*k > bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin() , bloomDay.end());
        int high = *max_element(bloomDay.begin() , bloomDay.end());
        // i will calculate the waiting days and then try to make bouquets ->
        // if i succeed then i will try to minimize it further if possible.
        int minDays = -1;
        while( low <= high){
            int mid = low + ( high - low )/2;
            int collect = doit(bloomDay , mid , k);
            if( collect >= m){
                minDays = mid;
                high=mid-1;
            }
            else low = mid+1;
        }   
        return minDays;    
    }
};
class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        int low = 1;
        int high = x/2;
        int ans = 1;
        while( low <= high){
            int mid = low + (high-low)/2;
            if(1LL*mid*mid == x) return mid;
            if( 1LL*mid*mid < x){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
        
    }
};
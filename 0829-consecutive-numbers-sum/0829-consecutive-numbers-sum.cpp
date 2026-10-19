class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 1;
        for( int k = 2; k < sqrt( 2 * n ); k++ ) {
            if ( ( n- ( k * ( k - 1 )/2) ) % k == 0) count++;
        }
        return count;
    }
};
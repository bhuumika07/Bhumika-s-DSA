class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0;
        int right = sqrt(c);
        while( left <= right )
        {
            long long sum = left*left*1LL + right*right*1LL;
            if( sum == c) return 1;
            if( sum < c) left++;
            else right--;
        }
        return 0;
        
    }
};
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int maxSum = 0;
        int sum = 0;
        while( right < nums.size())
        {
           sum = max( nums[right] , nums[right] + sum);
           maxSum = max( sum , maxSum);
           right++;
        }
        right  = 0;
        sum = 0;
        int minSum = 0;
        while( right < nums.size())
        {
            sum = min( nums[right] , sum + nums[right]);
            minSum = min( minSum , sum);
            right++;
        }

        return max(maxSum, abs(minSum));

        
    }
};
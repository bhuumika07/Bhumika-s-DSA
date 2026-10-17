class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int right = 0;
        int maxi = INT_MIN;
        while( right < nums.size())
        {
            if( sum + nums[right] < nums[right]) sum = 0;
            sum+=nums[right];
            maxi = max( maxi , sum);
            right++;
        }
        return maxi;
    }
};
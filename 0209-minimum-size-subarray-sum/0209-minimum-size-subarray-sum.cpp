class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int minlen = INT_MAX;
        int left=0; int right=0;
        long long sum = 0;
        while( right < nums.size())
        {
            sum+=nums[right];
            while( sum >= target && left <= right)
            {
                minlen = min( minlen , right-left+1);
                sum-=nums[left];
                left++;
            }
            right++;
        }
        if( minlen == INT_MAX) return 0;
        return minlen;
        
    }
};
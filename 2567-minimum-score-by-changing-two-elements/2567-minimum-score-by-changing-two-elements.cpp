class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int size = nums.size();
        if( size == 3) return 0;
        int ans = INT_MAX;
        ans = min( ans , nums[size-1] - nums[2]);
        ans = min( ans , nums[size-2] - nums[1]);
        ans = min( ans , nums[size-3] - nums[0]);
        return ans;
    }
};
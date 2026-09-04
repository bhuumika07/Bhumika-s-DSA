class Solution {
public:
    int dp[100004];
    int rob(vector<int>& nums) {
        int size = nums.size();
        if( size == 1) return nums[0];
        if( size == 2) return max( nums[0] , nums[1]);
        // memset(dp,-1,sizeof(dp));
        int backBy3=nums[0];
        int backBy2=nums[1];
        int ans = nums[0] + nums[2];
        int prev=0;
        for( int i=3;i<nums.size();i++)
        {
           prev = ans;
           ans = max( backBy2 , backBy3 ) + nums[i];
           backBy3 = backBy2;
           backBy2 =prev;

        }
        return max(prev,max(ans, nums[1]));
       
    }
};
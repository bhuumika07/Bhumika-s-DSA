class Solution {
public:
    // int dp[100005];
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];
        if( size == 2) return max(nums[0] , nums[1]);
        // tabulation solution
        // i will not rob the house if my (i-1)th robbery has a higher value than my (i-2)th robbery + the amount i am going to get from ith house .
        // memset(dp,-1,sizeof(dp));
        int state2=nums[0];
        int state1 =max(nums[1],nums[0]);
        int ans=0;
        
        for( int i=2;i<size;i++)
        {
            ans = max( state1, state2 + nums[i]);   
            state2 = state1;
            state1 = ans; 
        }
        return ans;
        
        
    }
};
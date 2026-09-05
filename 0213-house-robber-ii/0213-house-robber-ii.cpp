class Solution {
public:
    int dp[100005];
    int rob(vector<int>& nums) {
        int size = nums.size();

        if( size <= 3 ) return *max_element(nums.begin() , nums.end());

        memset( dp , -1 , sizeof(dp));
        // i will consider the first house.
        dp[0] = nums[0];
        dp[1] = max( nums[0] , nums[1]);
        for( int i=2; i<size-1;i++)
        {
            dp[i] = max( dp[i-1] , dp[i-2] + nums[i]);
        }
        int amount1 = dp[size-2];
        cout<<amount1<<endl;
        memset( dp , -1 , sizeof(dp));
        // i will consider the first house
        dp[0] = 0;
        dp[1]=nums[1];
        dp[2] = max( nums[1] ,nums[2]);
        for( int i=3; i<size;i++)
        {
            dp[i] = max( dp[i-1] , dp[i-2] + nums[i]);
        }
        int amount2 = dp[size-1];
        cout<<amount2;
        return max( amount1, amount2);

    }
};
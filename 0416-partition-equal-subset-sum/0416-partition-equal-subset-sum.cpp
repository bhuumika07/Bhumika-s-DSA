class Solution {
public:
    bool doit( vector<int>&nums , int target , int sum , int index , vector<vector<int>>&dp){
        if( sum > target) return 0;
        if( sum == target) return 1;
        if( index >= nums.size()) return 0;
        if(dp[sum][index] != -1) return dp[sum][index];
        int take = doit(nums , target , sum + nums[index] , index+1,dp);
        int dont = doit( nums , target , sum , index+1,dp);
        return dp[sum][index] = (take || dont);
    }
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for( int x : nums) target += x;
        if(target%2 != 0) return 0;
        vector<vector<int>>dp(target/2 + 1 , vector<int>(nums.size() , -1));
        return doit(nums,target/2,0,0,dp);
    }
};
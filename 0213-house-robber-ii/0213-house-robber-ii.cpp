class Solution {
public:
    int dp[1001][2];
    int doit( vector<int>&nums , int index , bool end){
        if( end && index == nums.size()-1) return 0;
        if(index >= nums.size()) return 0;
        if(dp[index][end] != -1) return dp[index][end];
        int take = nums[index] + doit(nums,index+2,end);
        int dont = doit(nums,index+1,end); 
        return dp[index][end] = max(take,dont);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        memset(dp,-1,sizeof(dp));
        int leaveEnd = doit( nums , 0 , 1);
        int takeEnd = doit( nums ,1,0);
        return max(leaveEnd , takeEnd);
    }
};
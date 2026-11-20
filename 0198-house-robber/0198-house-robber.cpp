class Solution {
public:
    int dp[101];
    int doit( vector<int>&nums , int index){
        if( index >= nums.size()) return 0;
        if(dp[index] != -1) return dp[index];
        int takeit = nums[index] + doit(nums,index+2);
        int dont = doit(nums,index+1);
        return dp[index] = max(takeit,dont);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return doit(nums , 0);
    }
};
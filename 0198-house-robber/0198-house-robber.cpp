class Solution {
public:
    int dp[101];
    int doit( vector<int>&nums , int index){
        if( index >= nums.size()) return 0;
        if(dp[index] != -1) return dp[index];
        int loot =  nums[index] + doit( nums , index + 2);
        int skip = doit( nums , index+1);
        return dp[index] = max( loot , skip);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return doit( nums , 0);
    }
};
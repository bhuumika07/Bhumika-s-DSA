class Solution {
public:
    int  dp[100005];
    bool doit( vector<int>&nums , int index){
        if( index >= nums.size() || index == nums.size()-1) return 1;
        if(dp[index] != -1) return dp[index];
        int n = nums[index];
        for( int i=1; i<=n; i++){
          int val = doit(nums,index+i);
           if(val) return dp[index] = 1;
        }
        return dp[index] = 0;
    }
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
       return doit(nums,0);
    }
};
class Solution {
public:
    int dp[41][16384];
    int doit(vector<int>& nums, int target, int index ,int xr)
    {
        if( index >= nums.size() && xr != target ) return INT_MIN;
        if(index >= nums.size() && xr == target) return 0;
        if(dp[index][xr] != -1) return dp[index][xr];
        int skip = doit(nums,target,index+1,xr);
        int take =1 + doit(nums,target,index+1,xr^nums[index]);
        return dp[index][xr] = max(skip , take);

    }
    int minRemovals(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
       int collected = doit(nums,target,0,0);
       if(collected < 0) return -1;
       return nums.size() -  collected ;
    }
};
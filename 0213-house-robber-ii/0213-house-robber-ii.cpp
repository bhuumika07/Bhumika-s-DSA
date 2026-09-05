class Solution {
public:
    int dp[100005];
    int  doit (vector<int>&nums , int idx , bool takeFirst)
    {
       int end = 0;
       if( !takeFirst) end=1;
       if( idx < end) return 0; 
       if( dp[idx] != -1) return dp[idx];
       int left = nums[idx];
       if( idx -2 >= end ) 
       {
        if(dp[idx-2] != -1) left += dp[idx-2];
        else left+= doit(nums , idx-2 , takeFirst);
       }
       int right=0;
       if( idx-1 >= end )
       {
        right+=nums[idx-1];
       }
       if( idx-3 >= end )
       {
        if( dp[idx-3] != -1) right +=dp[idx-3];
        else right+=doit(nums , idx-3 , takeFirst);
       }
       return dp[idx] = max(left, right);
    }
    int rob(vector<int>& nums) {
        // i will not consider the last house for time being.
        int size = nums.size();
        if( size == 1) return nums[0];
        memset( dp , -1 , sizeof(dp));
        int amount1 = doit( nums , size-2, 1 );
        memset(dp , -1 , sizeof(dp));
        int amount2 = doit( nums, size-1, 0);
        return max(amount1, amount2);
    }

};
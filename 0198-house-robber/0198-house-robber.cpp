class Solution {
public:
    int dp[100005];
    int doit( vector<int>&nums , int idx )
    {
        if( idx < 0) return 0;
        if (dp[idx] != -1) return dp[idx];
        // either i could take this one / or the element next to it.
        int choice1 = nums[idx];
        if( idx-2 >= 0)
        {
            if(dp[idx-2]!=-1) choice1+=dp[idx-2];
            else choice1+=doit(nums, idx-2);
        }
        int choice2=0;
        if(idx>=1) {choice2 = nums[idx-1] ;
        if( idx-3 >= 0)
        {
            if(dp[idx-3] != -1) choice2 += dp[idx-3];
            else choice2+=doit(nums,idx-3);
        }
        
        }
        return dp[idx] = max(choice1, choice2);

    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        memset(dp,-1,sizeof(dp));
        return doit(nums,size-1);
       
    }
};
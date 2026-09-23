class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total = 0;
        for( int x : nums) total+=x;
        int maxlen =-1;
        long long target = total - x;
        int right=0; int left=0;
        long long curr = 0;
        while( right < nums.size())
        {
            curr += nums[right];
            while( curr > target && left <=right)
            {
                curr-=nums[left];
                left++;
            }
            if( curr == target) maxlen =max( maxlen , right-left+1);
            right++;
        }
        if( maxlen == -1) return -1;
        return nums.size() - maxlen;
        
    }
};
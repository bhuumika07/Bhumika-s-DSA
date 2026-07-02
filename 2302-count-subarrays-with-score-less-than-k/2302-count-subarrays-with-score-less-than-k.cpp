class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long left=0;
        long long right=0;
        long long sum=0;
        long long len=0;
        long long count=0;
        while( right < nums.size())
        {
            len=right-left+1;
            sum+=nums[right];
            if( 1LL*sum*len < k) count+=(right-left+1);
            while(1LL*sum*len >= k)
            {
                sum-=nums[left];
                left++;
                len=right-left+1;
                if( 1LL*sum*len < k) count+=(right-left+1);
            }
            right++;
        }
        return count;
    }
};
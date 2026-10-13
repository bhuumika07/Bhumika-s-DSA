class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // negative values doesnt matter - will have to sort them according to their absolute values.
        if( nums.size() == 1) return nums[0]*nums[0]*1LL;
        for( int i=0; i<nums.size(); i++)
        {
            nums[i] = abs( nums[i]);
        }
        sort( nums.begin() , nums.end() , greater<int>());
        int left =0;
        int right = nums.size()-1;
        long long ans = 0;
        while( left < right )
        {
            if(nums.size()%2 != 0 && left == 0)
            {
                ans+=( nums[left]*nums[left]*1LL);
                left++;
                continue;
            }
            ans += (nums[left]*nums[left]*1LL) - ( nums[right]*nums[right]*1LL);
            left++;
            right--;
        }
        return ans;
    }
};
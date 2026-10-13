class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for( int i=0; i<nums.size(); i++)
        {
            nums[i] = abs( nums[i]);
        }
        sort( nums.begin() , nums.end() , greater<int>());
        int left =0;
        int right = nums.size()-1;
        long long ans = 0;
        if(nums.size()%2 != 0 )
            {
                ans+=( nums[0]*nums[0]*1LL);
                left++;
            }
        while( left < right )
        {
            ans += (nums[left]*nums[left]*1LL) - ( nums[right]*nums[right]*1LL);
            left++;
            right--;
        }
        return ans;
    }
};
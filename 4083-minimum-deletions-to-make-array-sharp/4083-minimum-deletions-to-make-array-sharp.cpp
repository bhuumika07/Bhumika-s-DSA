class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int count = 1;
        int ans = 0;
        for( int i = 1; i<nums.size(); i++)
        {
            if(nums[i] == nums[i-1]) count++;
            else
            {
                ans+= (count-1);
                count = 1;
            }
        }
        if( count != 1) ans+=(count-1);
        return ans;
    }
};
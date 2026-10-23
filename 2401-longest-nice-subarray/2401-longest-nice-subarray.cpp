class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxi = 1;
        int left = 0;
        int right = 1;
        int carry = nums[0];
        while( right < nums.size())
        {
            while ( ((carry & nums[right] )  != 0 )&& left < right)
            {
                carry = ( carry ^ nums[left]);
                left++;
            } 
            if( (carry & nums[right] )== 0) maxi = max( maxi , right -left+1);
            carry = carry | nums[right];
            right++;
        }
        return maxi;
    }
};
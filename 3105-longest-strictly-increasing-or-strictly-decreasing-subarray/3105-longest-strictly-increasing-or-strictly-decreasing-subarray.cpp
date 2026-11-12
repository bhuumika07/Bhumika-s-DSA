class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // chrck for increment
        int maxlen = 1;
        int left = 0;
        int right = 0;
        while( right < nums.size()-1){
            if(nums[right] < nums[right+1]) maxlen = max( maxlen , right -left + 2);
            else {
                left = right+1;
            }
            right++;
        }
        left = 0;
        right = 0;
        while( right < nums.size()-1){
            if(nums[right] > nums[right+1]) maxlen = max( maxlen , right -left + 2);
            else {
                left = right+1;
            }
            right++;
        }
        return maxlen;
    }
};
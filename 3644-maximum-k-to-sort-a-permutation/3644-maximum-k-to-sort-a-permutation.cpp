class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int first = -1;
        for( int i =0; i<nums.size(); i++)
        {
            if( nums[i] != i) if( first == -1) first = nums[i]; else first = first & nums[i];
        }
        if(first == -1) return 0;
        return first;
    }
};
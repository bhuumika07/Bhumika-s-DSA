class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int>misplaced;
        for( int i =0; i<nums.size(); i++)
        {
            if( nums[i] != i) misplaced.push_back( nums[i]);
        }
        if(misplaced.empty()) return 0;
        int first = misplaced[0];
        for( int i =1; i< misplaced.size(); i++)
        {
            first = first & misplaced[i];
        }
        return first;
    }
};
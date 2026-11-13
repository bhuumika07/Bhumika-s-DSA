class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        int size = nums.size();
        if(size == 1) return true;
        if(nums[0] > nums[1]) { nums[0] = nums[1] ; count++;}
        if(nums[size-1] < nums[size-2]){ nums[size-1] = nums[size-2]; count++;}
        if( count > 1) return 0;
        for( int i = 1; i<size-1; i++){
            if( nums[i] > nums[i+1]){
                if( count > 1) return 0;
                if(nums[i-1] > nums[i+1]) nums[i+1] = nums[i];
                else nums[i] = nums[i-1];
                count++;
            }
        }
        if( count > 1) return 0;
        return 1;
    }
};
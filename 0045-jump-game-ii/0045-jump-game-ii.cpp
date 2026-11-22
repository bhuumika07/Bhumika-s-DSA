class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int count = 0;
        int maxi = 0;
        int prev = 0;
        for( int i=0; i<nums.size(); i++){
           int jump = nums[i] + i;
           maxi = max( maxi , jump);
           if( i == prev){
            count++;
            prev = maxi;
           }
            if( prev >= nums.size() -1) return count;
        }
        return count;
    }
};
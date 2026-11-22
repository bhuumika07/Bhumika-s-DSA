class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        for( int i=0;i<nums.size();i++){
            if( i <= maxi){
                maxi = max( maxi , nums[i] + i);
            }
            else return 0;
        }
        return 1;
    }
};
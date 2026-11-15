class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int count = 0;
        for( int i=0; i<nums.size(); i++){
            int mini = nums[i];
            int andd = nums[i];
            if( andd == mini) count++;
            for( int j= i+1; j<nums.size(); j++){
                mini = min(mini , nums[j]);
                andd = andd&nums[j];
                if( andd == mini) count++;
            }
        }
        return count;
    }
};
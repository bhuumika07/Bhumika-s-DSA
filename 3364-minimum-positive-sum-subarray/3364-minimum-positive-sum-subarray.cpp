class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minSum = INT_MAX;
        for( int i=0; i<nums.size(); i++)
        {
            int sum = 0;
            for( int j =i; j< nums.size(); j++){
                int len = j-i+1;
                sum+=nums[j];
                if( sum > 0 && len >= l && len <= r) minSum = min( minSum , sum);
            }
        }
        if(minSum == INT_MAX) return -1;
        return minSum;
      
      
    }
};
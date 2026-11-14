class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minSum = INT_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;
        while( right < nums.size()){
            if(nums[right] > 0 && l == 1) minSum = min( minSum , nums[right]);
            sum+=nums[right];
            int len = right - left + 1;
            int ptr = left;
            int dumsum = sum;
            int length = len;
            while( length >= l){
                if( dumsum> 0 && length >= l && length <= r) minSum = min( minSum , dumsum);
                dumsum-=nums[ptr];
                ptr++;
                length = right - ptr + 1;
            }
            
             while( len > r){
                sum -= nums[left];
                left++;
                len = right -left+1;
             }
            if( sum> 0 && len >= l && len <= r) minSum = min( minSum , sum);
            right++;
        }
        if(minSum == INT_MAX) return -1;
        return minSum;
      
      
    }
};
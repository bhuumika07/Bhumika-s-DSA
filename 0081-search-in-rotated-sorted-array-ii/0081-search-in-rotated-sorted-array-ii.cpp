class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while( low <= high)
        {
            int mid = low + ( high - low)/2;
            if( nums[mid] == target) return 1;
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }
            else if(nums[low] <= nums[mid]) // means this part is sorted
            {
                if(nums[low] <= target && nums[mid] >= target) high = mid-1;
                else low =mid+1;
            }
            else
            {
                if( nums[mid] <= nums[high])
                {
                    if( target >=  nums[mid] && nums[high] >= target) low = mid+1;
                    else high =mid-1;
                }
            }
        }
        return 0 ;
    }
};
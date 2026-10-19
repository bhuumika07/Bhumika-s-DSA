class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // can it be done with one binary serach?
        int low = 0;
        int high = nums.size()-1;
        while( low <= high)
        {
            int mid = low + ( high - low )/2;
            if( nums[mid] >= target)  high = mid - 1;
            else low = mid+1;
        }
        if(low >= nums.size() || nums[low] != target ) return {-1 , -1};
        int first = low;
        low = 0;
        high = nums.size()-1;
        while( low <= high)
        {
            int mid = low + (high-low)/2;
            if( nums[mid] <= target) low = mid+1;
            else  high= mid - 1; 
        }
        return { first ,high};
       
    }
};
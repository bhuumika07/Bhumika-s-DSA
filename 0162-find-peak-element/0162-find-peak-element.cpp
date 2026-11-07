class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int high = nums.size()-2;
        if(high + 2 >= 2)
       { if(nums[high+1] > nums[high]) return high+1;
        if( nums[0] > nums[1]) return 0;}
        int low = 1;
        int ans = -1;
        while( low <= high){
            int mid = low + ( high - low )/2;
            if( nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) return mid;
            if(nums[mid] < nums[mid+1]){
                low = mid + 1;
            }
            else{
                high = mid-1;
            }
        }
        return 0;
    }
};
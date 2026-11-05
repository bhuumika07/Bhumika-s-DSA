class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //taking consideration of indices--> 
        // in the begining --> even index - 1st occurence
        //                      odd index -->2nd occurencccce
        // however after the single imposter -- this order changes ; so i will consider this thing only.
        if(nums.size() == 1 || nums[0] != nums[1]) return nums[0];
        int size = nums.size()-1;
        if(nums[size] != nums[size-1]) return nums[size];
        int low = 0;
        int high = size-2;
        while( low <= high)
        {
           int mid = low + (high - low)/2;
           if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
           if(nums[mid] == nums[mid+1] ){
            if(mid%2 == 0) low = mid+1;
            else high = mid-1;
           }else if(nums[mid] == nums[mid-1]){
                if(mid%2 != 0) low = mid+1;
                else high = mid-1;
           }
        }
        return -1;
        
    }
};
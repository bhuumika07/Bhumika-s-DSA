class Solution {
public:
    int doit( vector<int>&nums , int maxi){
        int count = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if( sum + nums[i] <= maxi){
                sum+=nums[i];
            }
            else{
                count++;
                if(nums[i] <= maxi) sum = nums[i];
                else return -1;
            }
        }
        if( sum > 0) count++;
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        // lets find the upper and lower bounds firstly.
        long long high = 0;
        for(int x : nums) high += x;
        long long low = *min_element(nums.begin() , nums.end());
        int ans = -1;
        while( low <= high){
            int mid = low + (high - low)/2;
            // lets check whether this minimum maximum sum is possible.
            int checker = doit( nums , mid);
            if( checker == -1 || checker > k){
                low = mid+1;
            }
            else{
                high = mid-1;
                ans = mid;
            }
        }
        return ans;
    }
};
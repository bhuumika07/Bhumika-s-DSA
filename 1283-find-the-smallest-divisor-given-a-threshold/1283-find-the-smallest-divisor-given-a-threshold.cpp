class Solution {
public:
    int doit( vector<int>&nums , int divisor){
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]/divisor);
            if(nums[i]%divisor != 0) sum++;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high =  *max_element( nums.begin() , nums.end());
        int ans = 1;
        while(low<=high){
            int mid = low + (high-low)/2;
            long long sum = doit(nums,mid);
            if( sum <= threshold){
                ans = mid;
                high = mid - 1;
            }else low = mid+1;
        }
        return ans;
    }
};
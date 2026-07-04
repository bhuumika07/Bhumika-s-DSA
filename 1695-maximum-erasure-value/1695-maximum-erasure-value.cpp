class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int maxiSum=0;
        int left=0;
        int right=0;
        int sum=0;
        while( right < nums.size())
        {
            if( mpp.find(nums[right]) != mpp.end())
            {
                int i= mpp[nums[right]];
                maxiSum= max( sum , maxiSum);
                while( left <=i )
                {
                   sum-=nums[left];
                   mpp.erase(nums[left]);
                   left++;
                }
            }
            mpp[nums[right]]=right;
            sum+=nums[right];
            maxiSum= max( maxiSum, sum);
            right++;
        }
        return maxiSum;
        
    }
};
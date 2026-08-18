class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int size =nums.size();
        int maxi=INT_MIN;
        for( int x : nums) mpp[x]++;
        if( k == size)
        {
            for( auto it : mpp) maxi=max( maxi,it.first);
            return maxi;
        }
        
        if( k != 1)
        {
            if( mpp[ nums[0] ] ==  mpp[nums[size-1]])
            {
                if( mpp[nums[0]] == 1)
                {
                    if( nums[0] > nums[size-1]) return nums[0];
                    else return nums[size-1];
                }
            }
            else if( mpp[nums[0]] == 1) return nums[0];
            else if(mpp[nums[size-1]] == 1) return nums[size-1];
        }
        else
        {
            for( auto it : mpp)
            {
                if( it.second == 1) maxi=max( maxi , it.first);
            }
        }
        if( maxi == INT_MIN) return -1;
        return maxi;
        
    }
};
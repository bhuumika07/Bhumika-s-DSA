class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        long long sum = 0;
        int left = 0;
        int right = 0;
        int ans = 0;
        unordered_map<long long,int> mpp;
        mpp[0]=1;
        while( right < nums.size())
        {
            sum+=nums[right];
            if( mpp.find( sum - target ) != mpp.end())
            {
                ans++;
                mpp.clear();
                mpp[0]=1;
                sum=0;
            }
            else mpp[sum]++;
            right++;
        }
        return ans;
    }
};
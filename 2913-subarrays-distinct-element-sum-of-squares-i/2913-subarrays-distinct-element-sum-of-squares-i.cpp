class Solution {
public:
    int sumCounts(vector<int>& nums) {
        // need to build all the subarrays and the square of the number of distinct elements in each of them forms the ans
        long long ans = 0;
        for( int i=0; i<nums.size();i++)
        {
            unordered_map<int,int>mpp;
            for( int j=i; j<nums.size(); j++)
            {
                mpp[nums[j]]++;
                ans += mpp.size()*mpp.size();
            }
        }
        return ans;
    }
};
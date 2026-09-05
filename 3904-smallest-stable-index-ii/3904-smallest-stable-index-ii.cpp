class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> maxs;
        vector<int> minis(nums.size());
        int maxi=0;
        int mini=INT_MAX;
        // maxs.push_back(nums[0]);

        for( int i=0; i<nums.size(); i++)
            {
                maxi= max( maxi ,nums[i]);
                maxs.push_back(maxi);
            }
        // minis[nums.size()-1]=(nums[nums.size()-1]);
        for( int i= nums.size()-1; i>=0; i--)
            {
                mini=min(mini,nums[i]);
                minis[i]=mini;
            }
        // vector<int> ans;
        for( int i=0; i<nums.size(); i++)
            {
                int s= maxs[i]- minis[i];
                if( s <=k) return i;
            }

        return -1;
        
    }
};
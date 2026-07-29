class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        int cnt=0;
        for( int i=0; i<nums.size();i++)
        {
            if( i>0 && nums[i]==nums[i-1]+1) cnt++;
            else cnt=1;

            if( i >= k-1)
            {
                if( cnt >= k) ans.push_back( nums[i]);
                else ans.push_back(-1);
            }
        }
        return ans;

        
    }
};
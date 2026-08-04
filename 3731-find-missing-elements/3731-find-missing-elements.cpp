class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> missi;
        int start = *min_element(nums.begin(), nums.end());
        int end = *max_element(nums.begin(), nums.end());
        map<int,int>mpp;
        for( int x : nums) mpp[x]++;
        for(int i= start+1; i<end; i++)
        {
            if(mpp.find(i) == mpp.end()) missi.push_back(i);
        }
        return missi;
        
    }
};
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid=(nums.size())/2;
        int ans=0;
        int right=0;
        while( right < nums.size())
        {
            ans += abs(nums[right]-nums[mid]);
            right++;
        }
        return ans;
        
        
    }
};
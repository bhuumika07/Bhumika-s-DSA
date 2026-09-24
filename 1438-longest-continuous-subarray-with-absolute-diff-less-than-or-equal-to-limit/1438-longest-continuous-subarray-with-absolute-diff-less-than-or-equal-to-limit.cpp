class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int>maxis;
        deque<int>minis;
        int left=0;
        int right=0;
        int ans=0;
        while(right < nums.size())
        {
            while(!maxis.empty() && nums[maxis.back()] < nums[right]) maxis.pop_back();
            while(!minis.empty() && nums[minis.back()] > nums[right]) minis.pop_back();
            maxis.push_back(right);
            minis.push_back(right);

            while (nums[maxis.front()] - nums[minis.front()] > limit) {

                if (maxis.front() == left)
                    maxis.pop_front();

                if (minis.front() == left)
                    minis.pop_front();

                left++;
            }
            ans= max( ans ,right-left+1);
            right++;
        }
        return ans;
    }
};
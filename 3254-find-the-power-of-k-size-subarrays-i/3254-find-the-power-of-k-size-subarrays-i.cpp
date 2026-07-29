class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        int cnt = 1;  // length of current consecutive increasing sequence

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1] + 1)
                cnt++;
            else
                cnt = 1;

            if (i >= k - 1) {
                if (cnt >= k)
                    ans.push_back(nums[i]);
                else
                    ans.push_back(-1);
            }
        }

        return ans;
    }
};
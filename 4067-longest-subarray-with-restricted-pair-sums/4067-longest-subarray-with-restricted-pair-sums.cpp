class Solution {
public:
    int maxSubarray(vector<int>& nums) {

        if (nums.size() <= 2) return nums.size();

        deque<pair<int,int>> dq;

        // pair sum -> number of pairs currently producing this sum
        unordered_map<int,int> sums;

        // value -> frequency in current window
        unordered_map<int,int> ele;

        int left = 0;
        int right = 0;
        int maxlen = 1;

        while (right < 2)
        {
            dq.push_back({nums[right], right});

            ele[nums[right]]++;

            right++;
            maxlen = 2;
        }

        // pair (0,1)
        sums[nums[0] + nums[1]]++;

        while (right < nums.size())
        {
            int x = nums[right];

            bool bad = false;

            // Case 1:
            // two existing elements already add up to x
            if (sums.find(x) != sums.end())
            {
                bad = true;
            }

            // Case 2:
            // existing element + x = another existing element
            if (!bad)
            {
                for (auto it : ele)
                {
                    int value = it.first;

                    if (ele.find(value + x) != ele.end())
                    {
                        bad = true;
                        break;
                    }
                }
            }

            // Shrink until x can safely enter
            while (bad)
            {
                int removed = nums[left];

                // Remove every pair:
                // removed + nums[i]
                for (auto it : dq)
                {
                    if (it.second <= left)
                        continue;

                    int sum = removed + it.first;

                    sums[sum]--;

                    if (sums[sum] == 0)
                        sums.erase(sum);
                }

                // Remove the element itself
                ele[removed]--;

                if (ele[removed] == 0)
                    ele.erase(removed);

                dq.pop_front();
                left++;

                // Check again with the smaller window

                bad = false;

                // Case 1
                if (sums.find(x) != sums.end())
                {
                    bad = true;
                }

                // Case 2
                if (!bad)
                {
                    for (auto it : ele)
                    {
                        int value = it.first;

                        if (ele.find(value + x) != ele.end())
                        {
                            bad = true;
                            break;
                        }
                    }
                }
            }

            // Now x can safely be inserted.
            // Create all pairs involving x.

            for (auto it : dq)
            {
                int sum = it.first + x;
                sums[sum]++;
            }

            ele[x]++;

            dq.push_back({x, right});

            maxlen = max(maxlen, right - left + 1);

            right++;
        }

        return maxlen;
    }
};
class Solution {
public:
    vector<vector<pair<long long, vector<int>>>> dp;
    vector<vector<bool>> visited;

    pair<long long, vector<int>> doit(
        vector<vector<int>>& intervals,
        int idx,
        int count
    ) {
        if (count == 0 || idx == intervals.size())
            return {0, {}};

        if (visited[idx][count])
            return dp[idx][count];

        visited[idx][count] = true;

        // Don't take
        auto call_1 = doit(intervals, idx + 1, count);

        // Find next non-overlapping interval
        int next = intervals.size();
        int low = idx + 1;
        int high = intervals.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (intervals[mid][0] > intervals[idx][1]) {
                next = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // Take
        auto call_2 = doit(intervals, next, count - 1);

        long long takeValue =
            intervals[idx][2] + call_2.first;

        // Don't take wins
        if (call_1.first > takeValue) {
            return dp[idx][count] = call_1;
        }

        // Take wins
        if (takeValue > call_1.first) {
            vector<int> temp = call_2.second;

            temp.push_back(intervals[idx][3]);
            sort(temp.begin(), temp.end());

            return dp[idx][count] = {takeValue, temp};
        }

        // Equal weight -> lexicographically smaller answer
        vector<int> takeIndices = call_2.second;
        takeIndices.push_back(intervals[idx][3]);

        sort(takeIndices.begin(), takeIndices.end());

        vector<int> dontIndices = call_1.second;
        sort(dontIndices.begin(), dontIndices.end());

        if (takeIndices < dontIndices) {
            return dp[idx][count] =
                {takeValue, takeIndices};
        }

        return dp[idx][count] =
            {call_1.first, dontIndices};
    }


    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        // Store original index
        for (int i = 0; i < intervals.size(); i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        dp.resize(
            n,
            vector<pair<long long, vector<int>>>(5)
        );

        visited.resize(
            n,
            vector<bool>(5, false)
        );

        auto ans = doit(intervals, 0, 4);

        return ans.second;
    }
};
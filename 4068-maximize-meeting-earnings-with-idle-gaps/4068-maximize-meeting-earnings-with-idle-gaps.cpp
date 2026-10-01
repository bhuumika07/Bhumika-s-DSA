class Solution {
public:
    vector<long long> dp;

    long long doit(vector<vector<int>>& meetings, int idx)
    {
        if (idx >= meetings.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        long long skip = doit(meetings, idx + 1);

        long long take = meetings[idx][2];

        int low = idx + 1;
        int high = meetings.size() - 1;
        int next = -1;

        // First meeting whose start >= current end
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (meetings[mid][0] >= meetings[idx][1])
            {
                next = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        if (next != -1)
        {
            take = max(
                take,
                (long long)meetings[idx][2]
                - meetings[idx][1]
                + best[next]
            );
        }

        return dp[idx] = max(skip, take);
    }

    vector<long long> best;

    long long maxEarnings(vector<vector<int>>& meetings)
    {
        sort(meetings.begin(), meetings.end());

        int n = meetings.size();

        dp.assign(n, -1);
        best.assign(n, 0);

        /*
            best[i] = max(start[j] + dp[j])
                     for all j >= i
        */

        // We need dp[j] first, so calculate states backwards.
        for (int i = n - 1; i >= 0; i--)
        {
            long long skip = (i + 1 < n) ? dp[i + 1] : 0;

            long long take = meetings[i][2];

            int low = i + 1;
            int high = n - 1;
            int next = -1;

            while (low <= high)
            {
                int mid = low + (high - low) / 2;

                if (meetings[mid][0] >= meetings[i][1])
                {
                    next = mid;
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            if (next != -1)
            {
                take = max(
                    take,
                    (long long)meetings[i][2]
                    - meetings[i][1]
                    + best[next]
                );
            }

            dp[i] = max(skip, take);

            // start[i] + dp[i]
            long long current = meetings[i][0] + dp[i];

            if (i == n - 1)
                best[i] = current;
            else
                best[i] = max(best[i + 1], current);
        }

        return dp[0];
    }
};
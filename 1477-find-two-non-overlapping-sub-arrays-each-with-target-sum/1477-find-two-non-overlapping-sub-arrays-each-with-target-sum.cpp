class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> ans( n , INT_MAX);

        int left = 0;
        int right =0;
        int sum=0;
        int ans1 = INT_MAX;
        while( right < n)
        {
            sum+=arr[right];

            while( sum > target)
            {
                sum-=arr[left];
                left++;
            }
            if( right > 0) ans[right] = ans[right-1];
            if( sum == target)
            {
                int len = right - left + 1;

                if( left > 0 && ans[left-1] != INT_MAX)
                {
                    ans1 = min( ans1, len + ans[left-1]);
                }

                ans[right] = min( ans[right] , len);
            }

            right++;
        }
        return (ans1==INT_MAX ? -1 : ans1);
        
    }
};
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> dp( k , 0);
        vector<long long> ans(k , 0);

        for( int x : nums)
        {
            vector<long long>newDp(k ,0);
            newDp[x%k]++;

            for( int r = 0; r <k; r++)
            {
                if(dp[r] == 0) continue;

                int newRemainder = ( r * (x%k) )%k;
                newDp[newRemainder] += dp[r];
            }

            for( int i=0; i<k; i++)
            {
                ans[i] += newDp[i];
            }
            dp=newDp;
        }
        return ans;

        
    }
};
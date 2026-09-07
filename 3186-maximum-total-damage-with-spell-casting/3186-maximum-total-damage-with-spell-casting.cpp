class Solution {
public:
    long long dp[100005];
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long,int>freq;
        for( int x : power )freq[x]++;
        vector<long long>temp;
        for( auto x : freq) temp.push_back(x.first);
        memset(dp, -1, sizeof(dp));
        sort(temp.begin() , temp.end());

        int n = temp.size();
        dp[0] = temp[0]*freq[temp[0]];

        for( int i=1; i<n; i++)
        {
            // dont take 
            dp[i]=dp[i-1];
            long long curr = temp[i]*freq[temp[i]];
            int j = i-1;
            while( j>=0 && temp[i] - temp[j] <= 2)j--;
            if( j >= 0) curr+=dp[j]; 
            dp[i] = max(dp[i] , curr);
        }
        return dp[n-1];
    }
};
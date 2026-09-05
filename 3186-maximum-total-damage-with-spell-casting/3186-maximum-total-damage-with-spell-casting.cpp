class Solution {
public:
    long long dp[100005];
    long long doit( vector<long long>&temp , int idx , unordered_map<long long,int>&freq)
    {
        if( idx < 0) return 0;
        if( dp[idx] != -1) return dp[idx];
        // donot take
        long long left = doit(temp , idx-1, freq);
        long long right = 1LL*temp[idx]*freq[temp[idx]];
        int j = idx-1;
        while( j>=0 && temp[idx] - temp[j]<=2)j--;
        right += doit(temp , j , freq);

        return dp[idx] = max( left , right);
    }
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long,int>freq;
        for( int x : power )freq[x]++;
        vector<long long>temp;
        for( auto x : freq) temp.push_back(x.first);
        memset(dp, -1, sizeof(dp));
        sort(temp.begin() , temp.end());
        return doit(temp , temp.size()-1 , freq);
    }
};
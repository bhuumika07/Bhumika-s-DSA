class Solution {
public:
    int dp[100005];
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int x: nums) freq[x]++;
        vector<int>temp;
        for(auto x:freq) temp.push_back(x.first);
        sort(temp.begin(), temp.end());
        if( temp.size() == 1) return temp[0]*freq[temp[0]];
        
        dp[0] = temp[0] * freq[temp[0]];
        if(temp[0]+1 == temp[1]) dp[1] = max(dp[0] , temp[1]*freq[temp[1]]);
        else dp[1] = dp[0] + temp[1]*freq[temp[1]];
        for(int i=2; i<temp.size();i++)
        {
            int val = temp[i]*freq[temp[i]];
            if(temp[i] != temp[i-1] + 1)
            {
                dp[i] = max( dp[i-1] ,dp[i-2]) + val;
            }
            else
            {
                dp[i]=max( dp[i-1] , val + dp[i-2]);
            }
        }
        return dp[temp.size()-1];

    }
};
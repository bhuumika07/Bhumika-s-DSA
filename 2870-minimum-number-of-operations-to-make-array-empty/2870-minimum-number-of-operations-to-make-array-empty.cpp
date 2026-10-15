class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for( int x : nums) mpp[x]++;
        long long ans = 0;
        for( auto it : mpp)
        {
           if( it.second < 2) return -1;
           ans += it.second/3;
           if( it.second % 3 != 0) ans++;
        }
        return ans;
        
    }
};
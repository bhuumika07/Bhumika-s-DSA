class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mpp;
        for( int x : tasks) mpp[x]++;
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
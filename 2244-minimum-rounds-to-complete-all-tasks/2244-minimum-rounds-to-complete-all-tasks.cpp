class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mpp;
        for( int x : tasks) mpp[x]++;
        long long ans = 0;
        for( auto it : mpp)
        {
           int two = 0;
           int three = 0;
           bool flag = 0;
           if( it.second < 2) return -1;
           if( it.second % 3 == 0) {three = it.second/3;}
           else three = it.second/3 + 1;
           if( it.second%2==0) {two = it.second/2;}
           else two = it.second/2+1;
           ans += min( two , three);
        }
        return ans;
        
    }
};
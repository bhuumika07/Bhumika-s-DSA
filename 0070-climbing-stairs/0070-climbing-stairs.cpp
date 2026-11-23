class Solution {
public:
    int climbStairs(int n) {
       int first = 1;
       int second = 1;
       int ans = 1;
        for( int i=2; i<=n;i++){
          ans = first + second;
          first = second;
          second = ans;
        }
        return ans;
    }
};
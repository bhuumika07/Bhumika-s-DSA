class Solution {
public:
    int fib(int n) {
    // for the tabulation solution we start from the edge case itself , is a bottom top approach - opposite to the recursive one which is top to bottom .
    // we start the process for the the edge case itself-- the point where we were stopping before , now we will be starting from their only.
    if(n == 0 || n == 1) return n; 
    // now instead of utilizing o(n) space -- we will space optimize it and move to constant space.
    int first=0;
    int second=1;
    int ans = first+second;
    for( int i=2; i<=n;i++)
    {
        ans= first + second ;
        first=second;
        second = ans;
    }
    return ans;

        
    }
};
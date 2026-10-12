class Solution {
public:
    bool threeFibonacciSum(int n) {
        long long first = 0;
        long long second = 0;
        long long sum = 1;
        while( sum <= n)
        {
            // if( first + second + sum == n) return 1;
            first = second;
            second = sum;
            sum = first + second;
            if( first + second + sum == n) return 1;
        }
        return 0;
    }
};
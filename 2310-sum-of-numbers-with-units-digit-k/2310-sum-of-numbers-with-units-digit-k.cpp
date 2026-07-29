class Solution {
public:
    int minimumNumbers(int num, int k) {
        if( num == 0) return 0;
        if( num < k) return -1;
        for( int i=1; i<=10;i++)
        {
            long long s = k*i;
            int n =s%10;
           if ((k * i) % 10 == num % 10 && k * i <= num)
            return i;
            // if( n == num%10) return i;
        }
        return -1;

        
    }
};
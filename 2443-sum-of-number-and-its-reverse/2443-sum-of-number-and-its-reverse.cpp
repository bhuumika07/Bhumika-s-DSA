class Solution {
public:
    int rev( int n)
    {
        int num=0;
        while( n > 0)
        {
            int t= n%10;
            num=num*10 + t;
            n/=10;
        }
        return num;
    }
    bool sumOfNumberAndReverse(int num) {
        for( int i=0; i<=num; i++)
        {
            if( i + rev(i) == num) return 1;
        }
        return 0;

        
    }
};
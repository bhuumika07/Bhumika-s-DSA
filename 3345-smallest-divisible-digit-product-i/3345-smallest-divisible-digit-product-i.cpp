class Solution {
public:
    int check( int n)
    {
        int pro=1;
        while( n > 0)
        {
            pro = pro *(n%10);
            n/=10;
        }
        return pro;
    }

    int smallestNumber(int n, int t) {
        int num=n;
        while( true )
        {
            if( check(num) % t == 0) return num;
            num++;
        }
        
    }
};
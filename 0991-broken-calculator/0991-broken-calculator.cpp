class Solution {
public:
    int brokenCalc(int startValue, int target) {
        long long count =0;
        long long start=startValue;
        if(start == target) return 0;
        while( start < target)
        {
            if( target % 2==0)
            {
                target/=2;
            }
            else target++;
            count++;
        }
        count+=( start- target);
        return count;
        
    }
};
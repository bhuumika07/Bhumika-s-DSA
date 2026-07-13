class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = to_string(low);
        int size = str.size();

        long long start = 0;
        int count=str[0]-'0';
        int adder=0;
        int safe=0;
        int go=1;
        for( int i=0; i<size; i++)
        {
            if( count == 9 && i+1 != size)
            {
                i=0;
                start=0;
                safe=0;
                go=1;
                adder=0;
                count=1;
                size++;
            }
            else 
            {start = start*10 + count;
            safe=safe*10+go;
            adder= adder*10 + 1;
            count++;
            go++;
            }
        }

        vector<int>ans;
        while( start <= high )
        {
            if( start >= low)ans.push_back(start);
            if( start % 10 != 9)
            {
                start+=adder;
            }
            else
            {
                adder= adder*10 + 1;
                safe=safe*10 + go;
                go++;
                start=safe;
            }
        }
        return ans;
        
    }
};
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int left=0;
        int right=0;
        int maxlen=1;
        bool larger=0;
        int count=1;
        if(arr.size() <= 1) return arr.size();
        while(right < arr.size()-1)
        {
            if(right==0)
            {
                if(arr[right] > arr[right+1]) larger=1;
                else larger=0;
                if( arr[right] != arr[right+1]) count=2;
                else count=1;
                right++;
                continue;
            }

            if( larger )
            {
                if(arr[right] < arr[right+1]) 
                {
                    larger=0;
                    count++;
                }
                else
                {
                    maxlen= max(maxlen , count);
                    if( arr[right] != arr[right+1]) count=2;
                    else count=1;
                }
            }
            else
            {
                if( arr[right] > arr[right+1])
                {
                    larger=1;
                    count++;
                }
                else
                {
                    maxlen = max( maxlen , count);
                    if( arr[right] != arr[right+1]) count=2;
                    else count=1;
                }
            }
            right++;
        }
        maxlen = max( maxlen , count);
        return maxlen;
    }
};
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0;
        vector<int>temp = arr;
        long long sum1= 0; long long sum2=0;
        sort( temp.begin() , temp.end());
        for( int i = 0;  i< arr.size(); i++)
        {
           sum1+=arr[i];
           sum2+=temp[i];
           if( sum1 == sum2) {count++; sum1=0; sum2=0;}
        }
        return count;
    }
};
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
       vector<int>freq(10,0);
       int count=0;
       for( int x : digits) freq[x]++;
       for( int i=1; i<=9; i++)
       {
        for( int j=0; j<=9;j++)
        {
            for(int k=0;k<=8;k+=2)
            {
                if(freq[i]>0 && freq[j] >0 && freq[k]>0)
                {
                    if( i == j && freq[i] <= 1) continue;
                    if( j==k && freq[j] <= 1 ) continue;
                    if( i == k && freq[k] <= 1) continue;
                    if( i==j && j==k && freq[j] < 3) continue;
                    count++;
                }
            } 
        }
       }
       return count;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int>freq(26,0);
       for( char c : tasks) freq[c-'A']++;
       int maxFreq = 0;
       int maxCount = 0;
       for( int i = 0; i<26; i++){
        if(freq[i] > maxFreq){
            maxFreq = freq[i];  maxCount = 1;
        }
        else if( freq[i] == maxFreq) maxCount++;
       }

       int ans = (maxFreq - 1)*(n+1) + maxCount;
       return max( (int)tasks.size() , ans);
    }
};
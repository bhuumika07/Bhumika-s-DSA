class Solution {
public:
    int numSplits(string s) {
        // find the total distincts
        unordered_map<char,int>freq;
        unordered_map<char,int>have;
        for( char c : s) freq[c]++;
        int distincts=freq.size();
        int left=0;
        int right=0;
        int count=0;
        for( int i=0; i<s.size();i++)
        {
            if( have.find(s[i]) == have.end())
            {
                left++;
                have[s[i]]++;
                freq[s[i]]--;
            }
            else
            {
                have[s[i]]++;
                freq[s[i]]--;
            }
            if( freq[s[i]] == 0) freq.erase(s[i]);
            right=freq.size();
            if( left == right) count++;
        }
        return count;
        
    }
};
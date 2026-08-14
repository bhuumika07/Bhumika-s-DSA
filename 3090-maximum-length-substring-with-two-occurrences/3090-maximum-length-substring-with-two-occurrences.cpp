class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxlen=0;
        int right=0;
        int left=0;
        unordered_map<char,int>current;
        while( right < s.size())
        {
            current[s[right]]++;
            while( current[s[right]] > 2)
            {
                current[s[left]]--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
        
        
    }
};
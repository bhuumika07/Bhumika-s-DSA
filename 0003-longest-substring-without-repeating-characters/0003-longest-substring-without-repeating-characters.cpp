class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int left = 0;
        int right =0;
        int maxlen = 0;
        while(right < s.size()){
            while(mpp.find(s[right]) != mpp.end()){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0) mpp.erase(s[left]);
                left++;
            }
            mpp[s[right]]++;
            maxlen = max( maxlen , right-left+1);
            right++;
        }
        return maxlen;
    }
};
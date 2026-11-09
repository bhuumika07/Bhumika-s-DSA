class Solution {
public:
    long long countValidSubstrings(string s) {
        long long count = 0;
        int left = 0;
        int right = 0;
        
        while( right < s.size()){
            if( right <= 1) count +=( right - left + 1);
            else{
                if(s[right-2] == 'a' && s[right-1] =='b' && s[right] == 'c'){
                    left = right-1;
                    count+=( right - left + 1);
                }
                else count+=( right - left + 1);
            }
            right++;
        }
        return count;
    }
};
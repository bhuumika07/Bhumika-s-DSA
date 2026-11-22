class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        int maxlen = 0;
        int left = 0; int right = 0;
        while( right < s.size()){
            if(s[right] == 'a' || s[right]=='e' || s[right] =='i' || s[right] =='o' || s[right] == 'u'){
                count++;
            }
            if( right - left + 1 > k){
                if(s[left] == 'a' || s[left]=='e' || s[left] =='i' || s[left] =='o' || s[left] == 'u')
                count--;
                left++;
            } 
            maxlen = max( maxlen, count);
            right++;
        }
        return maxlen;
    }
};
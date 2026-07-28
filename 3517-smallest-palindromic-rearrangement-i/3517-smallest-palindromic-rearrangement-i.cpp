class Solution {
public:
    string smallestPalindrome(string s) {
        int size = s.size();
        string str="";
        int i=0;
        for(i=0; i<size/2;i++)
        {
            str+=s[i];
        }
        sort( str.begin() , str.end());
        string ans= str;
        reverse( str.begin(), str.end());
        if(size%2!=0 && i < size) ans+=s[i];
        ans+=str;
        return ans;
        
    }
};
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string str="";
        int minlen=s.size();
        int left=0;
        int right=0;
        int count=0;
        while( right < s.size())
        {
            if(s[right] =='1') count++;

            while( count > k || s[left]=='0')
            {
                if(s[left] == '1') count--;
                left++;
            }
            if( count == k )
            {
                if( minlen > (right-left+1))
                {
                    minlen = right-left+1;
                    str=s.substr(left,minlen);
                }
                else if( minlen == right-left+1)
                {
                    if(!str.empty())
                    {
                        if( s.substr(left,minlen) < str) str = s.substr(left,minlen);
                    }
                    else str = s.substr(left,minlen);
                }

            }
            right++;
        }
        return str;
    }
};
class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        char lastseen = s[0];
        int lindex = 0;
        for( int i=1; i<s.size(); i++)
        {
            if(s[i] != s[i-1])
            {
                if( (i - lindex + 1)%2 == 0)
                {
                    ans ++;
                    s[i] = lastseen;
                }
                else 
                {
                    if( i+1 < s.size())
                    {
                        if( s[i+1] == lastseen)
                        {
                            s[i] = lastseen;
                            ans++;
                        }
                        else
                        {
                            lastseen = s[i];
                            lindex = i;
                        }
                    }
                    else ans++;
                }
            }
        }
        return ans;
        
    }
};
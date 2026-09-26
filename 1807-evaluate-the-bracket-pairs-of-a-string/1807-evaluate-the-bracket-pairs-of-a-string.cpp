class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map< string , string> mpp;
        for( int i=0; i<k.size(); i++)
        {
            mpp[ k[i][0]] = k[i][1];
        }

        string ans ="";
        string q = "";
        bool encountered = 0;
        for( int i=0; i<s.size();i++)
        {
            if( s[i] == '(')
            {
                encountered = 1;
                continue;
            }
            if( s[i] == ')')
            {
                if( mpp.find(q) != mpp.end())
                {
                    ans += mpp[q];
                }
                else ans +='?';
                q="";
                encountered = 0;
                continue;
            }
            if( encountered )
            {
                q += s[i];
            }
            else ans +=s[i];
        }
        return ans;
    }
};
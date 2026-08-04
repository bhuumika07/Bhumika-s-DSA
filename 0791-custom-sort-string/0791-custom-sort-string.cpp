class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mpp;
        for( char c : s) mpp[c]++;
        string ans="";
        for( char c : order)
        {
         
            if( mpp.find(c) != mpp.end())
            {
                mpp[c]--;
                ans+=c;
                while( mpp[c] > 0) { ans+=c; mpp[c]--;}

            }
        }
        for( int i=0; i<s.size();i++)
        {
            if( mpp[s[i]] > 0) 
            {
                ans+=s[i];
                mpp[s[i]]--;
            }
        }
        return ans;
        
    }
};
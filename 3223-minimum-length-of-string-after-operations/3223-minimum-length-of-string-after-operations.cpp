class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mpp;
        for( char c : s) mpp[c]++;
        int size = s.size();
        int count=0;
        for( auto it : mpp)
        {
            if( it.second % 2 == 0)
            {
             it.second-=2;
             size-=it.second;
            }
            else
            {
                it.second-=1;
                size-=it.second;
            }
        }
        return size;       
    }
};
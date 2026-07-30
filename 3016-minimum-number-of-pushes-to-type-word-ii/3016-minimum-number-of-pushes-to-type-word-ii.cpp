class Solution {
public:
  
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for( int i=0; i<word.size();i++)
        {
           freq[ word[i]-'a']++;
        }
        vector<int>vec;
        for( int i=0; i<26;i++)
        {
            if( freq[i] > 0) vec.push_back( freq[i]);
        }
        sort( vec.begin(), vec.end(), greater<int>());
        int count=0;
        int n=1;
        int c=0;
        for( auto it : vec)
        {
            count += it*n;
            c++;
            if( c==8)
            {
                c=0;
                n++;
            }
        }
        return count;
        
    }
};
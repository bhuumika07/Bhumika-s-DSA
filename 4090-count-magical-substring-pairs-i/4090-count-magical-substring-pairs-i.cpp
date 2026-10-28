class Solution {
public:
    int countMagicalPairs(string s) {
       int n = s.size();
       long long count = 0;
       // we will chgeck for every divider.
       for( int i = 0; i<n-1; i++)
       {
        vector<int>freqLeft(27,0);
        vector<int>freqRight(27,0);
        int distincts = 0;
        vector<bool>seen(27,0);
        // we will expand towards the left.
        for( int left = i; left >=0; left--)
        {
            if(seen[s[left] - 'a'] == 0){
                distincts++;
                seen[s[left] - 'a']  = 1;
            }
            freqLeft[distincts]++;
        }
        fill(seen.begin() , seen.end() , 0);
        distincts = 0;
        for( int right = i+1; right<n; right++)
        {
            if(seen[s[right] - 'a'] == 0)
            {
                distincts++;
                seen[s[right] - 'a'] = 1;
            }
            freqRight[distincts]++;
        }

        for( int k = 0; k<seen.size(); k++)
        {
            count+=( 1LL * freqRight[k] * freqLeft[k]);
        }
       }
       return count;
    }
};
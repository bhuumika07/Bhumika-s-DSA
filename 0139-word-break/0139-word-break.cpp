class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // tabulation approach.
        // starting condition would be the base case of memoization
        // i.e  when it reaches the end of the string
        unordered_set<string>contains;
        for( string &word : wordDict) contains.insert(word);
        int dp[305];
        memset(dp , -1, sizeof(dp));
        int size = s.size();
        dp[size]=1;
        for( int i = size-1; i>=0; i--)
        {
            string p="";
            bool found=0;
            for( int j=i; j<size;j++)
            {
                p+=s[j];
                if(contains.find(p) != contains.end())
                {
                    if(dp[j+1] == 1)
                    {
                        found=1;
                        break;
                    }
                }
            }
            if(found) dp[i]=1;
            else dp[0]=0;
        }
        return dp[0];

        
    }
};
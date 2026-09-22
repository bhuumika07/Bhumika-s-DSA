class Solution {
public:
    int dp[2001][4];
    int pal[2001][2001];

    bool isPalindrome( string&s , int left , int right)
    {
        if(pal[left][right] != -1) return pal[left][right];
        int l = left;
        int r = right;
        while( l <= r)
        {
            if(s[l] != s[r]) return pal[left][right]=0;
            l++;
            r--;
        }
        return pal[left][right] = 1;
    }

    bool solve( string&s , int idx , int cuts)
    {   if( idx == s.size() && cuts == 3) return 1;
        if( cuts > 3) return 0;
        if(dp[idx][cuts] != -1) return dp[idx][cuts];
        bool verdict = 0;
        for(int i=idx; i<s.size();i++)
        {
            if(isPalindrome(s,idx,i))
            {
                if(solve(s , i+1 , cuts + 1))
                {
                    verdict=1;
                    return dp[i+1][cuts+1]=1;
                }
            }
        }
        return dp[idx][cuts]=verdict;
    }
    bool checkPartitioning(string s) {
        // need to build a dp having states - start and end , telling whether the string within this range is a palindrome or not.
        memset(pal, -1 , sizeof(pal));
        int size = s.size();
        for( int i=0; i<size;i++)
        {
            pal[i][i]=1;
            if( i+1 < size && s[i] == s[i+1]) pal[i][i+1]=1; 
        }

        memset(dp,-1,sizeof(dp));
        return solve(s,0,0);
        
    }
};
class Solution {
public:
    int dp[1000];
    int doit( string&s , int idx)
    {
       // taking one by one
       if( idx == s.size()) return 1;
       if( s[idx] == '0') return 0;
       if( dp[idx] != -1) return dp[idx];
       int singlee = doit( s, idx+1);
       int doublee=0;
       if( idx+1 < s.size())
       {
            int num =s[idx]-'0';
            num = num*10 + s[idx+1] -'0';
            if(num <= 26 )  doublee = doit( s, idx+2);;
        } 
    
        return dp[idx] = singlee + doublee;
    }
    int numDecodings(string s) {
        memset( dp , -1 , sizeof(dp));
        return doit(s,0);
    }
};
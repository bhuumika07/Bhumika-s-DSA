class Solution {
public:
    long long appealSum(string s) {
        long long ans =0;
        long long curr=0;
        vector<int>last(26,-1);
        for( int i=0; i<s.size();i++)
        {
            int ch = s[i]-'a';
            curr+= i-last[ch];
            ans+=curr;
            last[ch]=i;
        }
        return ans;
        
    }
};
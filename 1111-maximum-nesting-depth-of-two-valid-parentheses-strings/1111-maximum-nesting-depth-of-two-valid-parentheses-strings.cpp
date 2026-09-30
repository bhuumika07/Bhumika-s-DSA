class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>ans;
        int len = 0;
        for(char c : seq)
        {
            if(c == '(')
            {
                len++;
                ans.push_back( len%2 );
            }
            else
            {
                ans.push_back( len%2);
                len--;
            }
        }
        return ans;
      
        
    }
};
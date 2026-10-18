class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int>ans( s.size() , 0);

        for( int i = 0; i<s.size(); i++)
        {
            int startr = startPos[0];
            int startc = startPos[1]; 
            int count = 0;
            for(int j = i; j<s.size(); j++)
            {
                if(s[j] == 'R') startc++;
                else if( s[j] == 'L') startc--;
                else if( s[j] == 'U') startr--;
                else startr++;
                if( startr < 0 || startc < 0 || startr >= n || startc >= n) break; 
                count++;
            }
            ans[i] = count;
        }
        return ans;
        
    }
};
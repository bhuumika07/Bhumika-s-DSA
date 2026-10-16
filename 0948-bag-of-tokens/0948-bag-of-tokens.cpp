class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort( tokens.begin() , tokens.end());
        long long score = 0;
        long long fin = 0;
        int left  = 0;
        int right = tokens.size()-1;
        while( left <= right)
        {
            if( power >= tokens[left]) {power-= tokens[left]; score++; fin = max( fin , score);left++;}
            else
            {
                if( score < 1) return fin;
                power+=tokens[right];
                right--;
                score--;
            }
            
        }
        return fin;
        
    }
};
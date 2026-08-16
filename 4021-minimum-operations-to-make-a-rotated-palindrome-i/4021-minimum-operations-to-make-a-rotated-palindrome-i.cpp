class Solution {
public:
    int minOperations(string s) {
        int ans = INT_MAX;
        int size=s.size();

        for( int j=0; j<size;j++)
        {
            int cost = j;
            for( int i=0; i<size/2;i++)
            {
                char left = s[(i+j)%size];
                char right=s[(size-1-i+j)%size];
                int diff= abs( right -left);
                cost+= min(diff , 26-diff);
            }
            ans=min( ans , cost);
        }
        return ans;
    }
};
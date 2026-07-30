class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time=0;
        stack<pair<char,int>>st;
        bool push=1;
        for( int i=0; i<colors.size();i++)
        {
            while( !st.empty() && st.top().first == colors[i])
            {
                if( neededTime[ st.top().second ] <= neededTime[i])
                {
                    time += neededTime[ st.top().second ];
                    st.pop();
                    push=1;
                }
                else
                {
                    time+=neededTime[i];
                    push=0;
                    break;
                }
            }
            if( push ) st.push( { colors[i] , i});
            else push=1;
        }
        return time;
        
    }
};
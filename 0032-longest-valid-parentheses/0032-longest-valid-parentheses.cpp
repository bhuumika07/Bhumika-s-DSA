class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int>st;
        for( int i=0; i<n;i++)
        {
            if( s[i] ==')' && !st.empty() && s[st.top()] == '(') st.pop();
            else st.push(i);
        }
        int maxlen=0;
        if(st.empty()) return n;
        maxlen = max( maxlen , n - st.top() - 1);
        while(!st.empty())
        {
            int first =  st.top();
            st.pop();
            int second = 0;
            if(!st.empty()) {second = st.top();
            maxlen = max( maxlen , first - second - 1);}
            else maxlen = max( maxlen , first - second );
        }
        return maxlen;
        
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // previous smaller bar
        vector<int>prev(n,-1);
        stack<int>st;
        for( int i=0; i<n; i++)
        {
            while( !st.empty() && heights[st.top()] > heights[i]) st.pop();
            if( !st.empty()) prev[i]= st.top();
            st.push(i);
        }

        while( !st.empty()) st.pop();  // emptying out the stack

        // next smaller bar
        vector<int>next(n,n);
        for( int i=n-1; i>=0; i--)
        {
            while( !st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if( !st.empty()) next[i]=st.top();
            st.push(i);
        }
        int maxi = 0;
       for(int i=0;i<n;i++)
       {
        int k= heights[i]*(next[i]- prev[i]-1);
        maxi=max(maxi,k);
       }
       return maxi;

        
    }
};
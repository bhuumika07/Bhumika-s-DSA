class Solution {
public:
    long long minimumSum(vector<int>&nums)
    {
        long long mod = 1e7 + 9;
        int n = nums.size();
        stack<int>st;
        // previous smaller element 
        vector<int>prev(n,-1);
        for( int i= 0 ; i<n; i++)
        {
            while( !st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if( !st.empty()) prev[i]=st.top();
            st.push(i);
        }

        //empty out the stack
        while(!st.empty()) st.pop();

        // next smaller element
        vector<int>next(n,n);
        for(int i = n-1; i>=0; i--)
        {
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            if(!st.empty()) next[i]=st.top();
            st.push(i);
        }
        long long ans=0;

        for( int i=0; i<n;i++)
        {
            long long right = next[i] - i;
            long long left = i - prev[i];
           ans += 1LL * right * left * nums[i];
        }
        return ans;
    
    }

    long long maximumSum( vector<int>&nums)
    {
        long long mod = 1e7 + 9;
        int n = nums.size();
        stack<int>st;
        // next greater element
        vector<int>next(n,n);
        for( int i= n-1; i>=0; i--)
        {
            while( !st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if( !st.empty()) next[i]=st.top();
            st.push(i);
        }

        // empty out the stack
        while(!st.empty())st.pop();

        vector<int>prev(n,-1);
        for( int i = 0; i<n; i++)
        {
            while( !st.empty() && nums[st.top()] < nums[i]) st.pop();
            if(!st.empty()) prev[i]=st.top();
            st.push(i);
        }

        long long ans = 0;
        for( int i=0; i<n; i++)
        {
            int right = next[i]-i;
            int left = i-prev[i];
           ans += 1LL * right * left * nums[i];

        }
        return ans;
    } 
    long long subArrayRanges(vector<int>& nums) {
         return maximumSum(nums)-minimumSum(nums);
        
    }
};
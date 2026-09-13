class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        unordered_map<int,vector<int>>freq;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]].push_back(i);
        }
        int n = nums.size();
        vector<int>small( n , n);
        stack<int>st;
        for( int i=n-1; i>=0;i--)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if(!st.empty()) small[i] = st.top();
            st.push(i);
        }
        long long ans=0;
        for( int i=0; i<n;i++)
        {
            int val = small[i];
            int range = val -i - 1;
            int left = i; int right = val;
            auto &temp = freq[nums[i]];
            int dups= lower_bound( temp.begin() , temp.end() , right) -upper_bound(temp.begin() , temp.end() , i);
            range-=dups;
            ans+=range;
        }
        return ans;
    }
};
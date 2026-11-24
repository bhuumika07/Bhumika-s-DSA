class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int>NGE(n , -1);
        stack<int>st;
        for( int i = n-1; i>=0 ; i--){
            while(!st.empty() && st.top() < nums2[i]) st.pop();
            if(!st.empty()) NGE[i] = st.top();
            st.push(nums2[i]);
        }
        unordered_map<int,int>mpp;
        for( int i=0; i<n; i++){
            mpp[nums2[i]] = i;
        }
        int m = nums1.size();
        vector<int>ans(m,0);
        for(int i=0; i<m; i++){
            ans[i] = NGE[mpp[nums1[i]]];
        }
        return ans;
    }
};
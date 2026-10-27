class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long s = 0;
        priority_queue<int>pq;
        for( int x : nums) pq.push(x);
        while(!pq.empty() && k--)
        {
            int val = pq.top();
            pq.pop();
            s+=val;
            pq.push( ceil(val/3.0) );
        }
        return s;
    }
};
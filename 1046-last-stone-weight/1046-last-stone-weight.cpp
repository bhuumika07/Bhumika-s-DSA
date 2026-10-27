class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for( int x : stones) pq.push(x);
        while(pq.size() > 1)
        {
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            if( f  == s) continue;
            pq.push(abs(s-f));
        }
        if(pq.empty()) return 0;
        return pq.top();
      
    }
};
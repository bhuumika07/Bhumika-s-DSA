class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        queue< pair<pair<int,int>,char>>q;
        priority_queue< pair<int,char> > pq;
        vector<int>chars(26,0);
        for( char c : tasks) chars[c-'A']++;
        for(int i = 0; i<26;i++){ if( chars[i] > 0) pq.push( {chars[i] , i + 'A'} );}
        int interval = 0;
        while(!pq.empty() || !q.empty()) 
        {
           if(!pq.empty()){
            auto [freq , c] = pq.top();pq.pop();
            if( freq -1 > 0){ q.push({{interval + n + 1 , freq - 1 }, c});}}
            interval++;
            if(!q.empty() && q.front().first.first <= interval)
            {
                auto things = q.front();q.pop();
                int freq = things.first.second;  char ele = things.second;
                pq.push({freq,ele});
            }
        }
        return interval;

    }
};
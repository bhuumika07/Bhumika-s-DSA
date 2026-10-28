class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mpp;
        for( int c : s) mpp[c]++;
        priority_queue< tuple<int,char> >pq;
        for( auto it : mpp) pq.push( {it.second , it.first});
        string ans = "";
        while(!pq.empty())
        {
            if(pq.size() == 1 )
            {
                auto [freq,c] = pq.top();
                if( freq > 1) return "";
            }
            auto [freq,c] = pq.top();
            pq.pop();
            if( ans.empty() || ans.back() != c)
            {
                ans+=c;
                if( freq-1 != 0) pq.push({freq-1 , c});
            }
            else
            {
               auto [freq2,l] = pq.top();
               pq.pop();
               ans+=l;
               if(freq2-1 != 0) pq.push( {freq2-1 , l});
               pq.push({freq , c});
            }
        }
        return ans;
    }
};
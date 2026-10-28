class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue< tuple<int,char> >pq;
        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});
        string ans ="";
        while(!pq.empty())
        {
            auto [freq , ele] = pq.top(); pq.pop();
            if( ans.empty() || ans.back() != ele || ans.size() == 1){
                ans+=ele;
                if( freq-1 != 0) pq.push({freq-1 , ele});
            }
            else
            {
                int n = ans.size();
                if(ans[n-1] == ans[n-2])
                {
                    if(pq.empty()) return ans;
                    auto [freq1, ele1] = pq.top();
                    pq.pop();
                    ans+=ele1;
                    if(freq1 - 1 > 0) pq.push({freq1-1 , ele1});
                    pq.push({freq , ele});
                }
                else{
                    ans+=ele;
                    if( freq-1 != 0) pq.push({freq-1 , ele});
                }
            }
        }
        return ans;
    }
};
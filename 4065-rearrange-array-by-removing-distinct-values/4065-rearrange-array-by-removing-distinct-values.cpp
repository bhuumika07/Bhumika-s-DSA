class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int>mpp;
        for( int x : nums) mpp[x]++;
        vector<int>ans;
        while(!mpp.empty())
        {
           vector<int>remove;
           for( auto &[first,second] : mpp)
           {
            ans.push_back( first);
            second--;
            if( second == 0) remove.push_back(first);
           }

           for( int x : remove) mpp.erase(x);
        }
        return ans;
        
    }
};
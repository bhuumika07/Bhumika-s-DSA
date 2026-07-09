class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
         if( nums.size() % k != 0) return 0;

        map<int,int>freq;
        for( int i=0; i<nums.size();i++) freq[nums[i]]++;

        while( !freq.empty() )
        {
            int start = freq.begin()->first;

            for(int i=0;i<k;i++)
            {
                int curr = start + i;
                if( freq.find( curr ) == freq.end()) return 0;

                freq[curr]--;
                if(freq[curr] == 0) freq.erase(curr);
            }
        }

        return 1;  
        
    }
};
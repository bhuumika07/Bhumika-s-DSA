class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int>store;
        for( int x : nums) store.insert(x);
        long long sum=nums[0];
        long long fsum=nums[0];
        int len=1;
        int maxlen=1;
        for( int i=1; i<nums.size();i++)
        {
            if( nums[i] == nums[i-1]+1)
            {
                len++;
                sum+=nums[i];
            }
            else
            {
                break;
            }
        }
        while( true )
        {
            if( store.find( sum) == store.end()) return sum;
            sum++;
        }
        return 0;
    }
};
class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map< pair<int,int> , int> mpp;
        for( int i=1; i<nums.size();i++)
        {
            int first = nums[i-1];
            int second = nums[i];
            if(first > second) mpp[ {second,first}]++;
            else mpp[ {first , second} ]++;
        }
        int ans = 0;
        int maxi =0 ;
        for( auto it : mpp)
        {
            int first = it.first.first;
            int second = it.first.second;
            if( first == second ) ans+= it.second;
            else maxi = max( maxi , it.second);
        }
        return ans+maxi;
        
    }
};
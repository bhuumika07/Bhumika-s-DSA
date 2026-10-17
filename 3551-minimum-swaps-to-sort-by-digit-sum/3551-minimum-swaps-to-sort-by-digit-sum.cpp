class Solution {
public:
    // static bool cmp( const pair<long long , int>& a , const pair<long long,int>&b)
    // {
    //     if( a.first > b.first ) return 0;
    //     if( a.first == b.first && a.second > b.second) return 0;
    //     return 1;
    // }
    int minSwaps(vector<int>& nums) {
        vector<pair<int, int> > unsorted;
        for( int i=0; i<nums.size(); i++)
        {
            long long add = 0;
            long long num = nums[i];
            while( num > 0)
            {
                add += num%10;
                num/=10;
            }
            unsorted.push_back( {add,nums[i]} );
        }
        vector< pair<int,int> > sorted = unsorted;
        sort( sorted.begin() , sorted.end());
        unordered_map< int , int > indices;
        for( int i = 0; i< nums.size(); i++ )
        {
            indices[ unsorted[i].second ] = i;
        }
        int count = 0;
        for( int i = 0; i< nums.size(); i++)
        {
            // ab i need to check what should be at my i-th index and where is it.
            int wanted = indices[ sorted[i].second ];
            if( wanted == i) continue;
            // now where should i throw the number that is present at my i-th index right now.
            count++;
            swap( unsorted[i] ,unsorted[wanted]);
            indices[ unsorted[wanted].second ] = wanted;
            indices[ sorted[i].second] = i;
        }
        return count;

    }
};
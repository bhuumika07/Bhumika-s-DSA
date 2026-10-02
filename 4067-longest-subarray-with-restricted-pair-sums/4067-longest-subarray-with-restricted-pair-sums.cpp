class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        while( nums.size() <= 2) return nums.size();
        unordered_map<int,int>sums;
        unordered_map<int,int>ele;
        deque< pair<int,int> > dq;
        int left = 0;
        int right = 0;
        int maxlen = 1;
        while( right < nums.size())
        {
            bool bad = 0;
            
            // case 1 : what if there already exists 2 elements that made a pairsum equal to me
            if( sums.find( nums[right]) != sums.end())
            {
                bad = 1;
            }
            // case 2 : will check if i when added to current element create a already existing element
            if( !bad )
            {
                int curr = nums[right];
                for( auto it  : ele)
                {
                    if( ele.find( curr + it.first) != ele.end())
                    {
                        bad = 1;
                        break;
                    }
                }
            }

            // now we will validate the window by shrinking appropriately
            while( bad )
            {
                int removed = nums[left];
                // i will eliminate all the pairsums that were formed using this elemnt;
                for( auto it : dq)
                {
                    if( it.second > left )
                    {
                        int sum = removed + it.first;
                        sums[sum]--;
                        if( sums[sum] == 0) sums.erase( sum );
                    }
                }
                // remove the element now
                ele[ removed]--;
                if( ele[removed] == 0) ele.erase(removed);
                dq.pop_front();
                left++;

                // now we will check whether after this operation , window become valid or not

                bad = 0;
                // case 1 : sum still exists
                if( sums.find( nums[right]) != sums.end()) bad = 1;
                //case2 : am i pairing it with somebody to produce the already present element.
                if(!bad)
                {
                    for( auto it : ele)
                    {
                        int value = nums[right] + it.first;
                        if( ele.find( value ) != ele.end())
                        {
                            bad = 1;
                            break;
                        }
                    }
                }
            }
            // now after making the window valid , now we will be adding new pairsums
            for( auto it : dq)
            {
                int sum = it.first + nums[right];
                sums[sum]++;
            }
            ele[nums[right]]++;
            dq.push_back( {nums[right] , right});
            maxlen = max( maxlen , right-left+1);
            right++;
        }
        return maxlen;
    }
};
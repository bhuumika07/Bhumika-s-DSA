class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
          int mod = 1e9 + 7;
        long long ans = 0;
        for( int i=0; i<nums1.size(); i++)
        {
            ans += ( abs( nums1[i] - nums2[i]))%mod;
        }
        // now for every index i will check.
        vector<int>arr = nums1;
        sort( nums1.begin() , nums1.end());
        long long temp = ans;
        long long mini = ans;
        for( int i = 0; i<nums2.size(); i++)
        {
            // i will check the term nearest to me.
            temp = ans;
            auto it = upper_bound( nums1.begin() , nums1.end() , nums2[i]);
            int index ;
            if( it  == nums1.end()) index = nums1.size() - 1;
            else index = it - nums1.begin();
            temp -= (abs( arr[i] - nums2[i]))%mod;
            // here also there are two possibilities -- either the element greater than me or the element smaller than me will give the right ans.
            int option1 = INT_MAX;
            int option2 = 0;
            if( index > 0) option1 = abs( nums1[index-1] - nums2[i]);
            option2 = abs( nums1[index] - nums2[i]);

            temp+= (min( option1 , option2))%mod;

            mini = min( temp , mini);
        }
        return min( mini , ans)%mod;
        
    }
};
class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int even=0;
        int odd=0;
        int count=0;
        for( int i=0; i<nums.size();i++)
        {
            even=0;
            odd=0;
            for( int j=i; j<nums.size();j++)
            {
                if(nums[j]%2==0) even++;
                else odd++;
                if( odd!=0 && 1LL*b* even <= a*odd*1LL) count++;
            }
        }
        return count;

        
    }
};
class Solution {
public:
    
    int rob(vector<int>& nums) {
        int size = nums.size();

        if( size <= 3 ) return *max_element(nums.begin() , nums.end());

        int secondLast= nums[0];
        int last = max( nums[0] , nums[1]);
        int ans1=0;
        for( int i=2; i<size-1;i++)
        {
            ans1 = max( last , secondLast + nums[i]);
            secondLast = last;
            last=ans1;
        }
      
        secondLast=nums[1];
        last= max( nums[1] ,nums[2]);
        int ans2=0;
        for( int i=3; i<size;i++)
        {
            ans2= max(last ,secondLast+ nums[i]);
            secondLast = last;
            last = ans2;
        }
      
        return max( ans1,ans2);

    }
};
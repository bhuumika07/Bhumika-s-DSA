class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> ans (nums.size());
        ans[0]=nums[0];
        for( int i=1; i<nums.size(); i++)
            {
                ans[i]= max(nums[i], ans[i-1]);
            }
        vector<int> gcc(nums.size());
        for(int i=0; i<nums.size();i++)
            {
                gcc[i]=gcd(ans[i],nums[i]);
            }
        sort(gcc.begin(), gcc.end());
        long long sum=0;
        int x=nums.size()-1;
        for(int i=0; i<nums.size()/2;i++)
            {
                sum+= ( gcd(gcc[i], gcc[x-i]));
                
            }
        return sum;
        
    }
};
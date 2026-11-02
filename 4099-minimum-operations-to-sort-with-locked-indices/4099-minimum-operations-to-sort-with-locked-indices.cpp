class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        long long count = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] != i+1)
            {
                int start = 0;
                int end =0;
                if(i > nums[i])
                {
                    end = i;
                    start = nums[i]-1;
                }
                else
                {
                    end = nums[i]-1;
                    start=i;
                }
                while( start <= end)
                {
                    if(locked[start] && k > 0)
                    {
                        count++;
                        locked[start] = 0;
                        k--;
                    }
                    else if( locked[start]) return -1;
                    start++;
                }
            }
        }
        for(int i = 0; i<nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[i] > nums[j]) {count++;}
            }
        }
        return count;
    }
};
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {

        long long count = 0;
        long long prefix = 0;

        unordered_map<int, long long> freq;
        freq[0] = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % modulo == k)
                prefix++;

            int required = ((prefix - k) % modulo + modulo) % modulo;

            count += freq[required];

            freq[prefix % modulo]++;
        }

        return count;
    }
};
class Solution {
public:
    int countStaircase(vector<int>& nums) {
       long long count = 0;
        for( int i = 0; i<nums.size(); i++)
        {
            unordered_map<int,int>order;
            unordered_map<int,int>freq;
            int k = 1;
            int hogye = 0;
            for( int j = i; j<nums.size();j++)
            {
                if( order.find(nums[j]) == order.end()) {
                    order[nums[j]] = k;
                    k++;
                }
                freq[nums[j]]++;
                if( order[nums[j]] < freq[nums[j]]) hogye--;
                if(order[nums[j]] == freq[nums[j]]) {hogye++;}
                if( hogye == k-1) count++;
            }
        }
        return count;
    }
};
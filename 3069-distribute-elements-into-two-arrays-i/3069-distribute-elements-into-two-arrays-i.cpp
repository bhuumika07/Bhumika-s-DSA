class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        int a = nums[0];
        int b=nums[1];
        vector<int>arr1;
        vector<int>arr2;
        arr1.push_back(a);
        arr2.push_back(b);
        // vector<int>arr2;
        for( int i=2; i<n; i++)
        {
            if( a > b)
            {
                arr1.push_back(nums[i]);
                a=nums[i];
            }
            else
            {
                arr2.push_back(nums[i]);
                b=nums[i];
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;

        
    }
};
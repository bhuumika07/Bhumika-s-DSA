class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = *min_element( nums.begin() , nums.end() );
        int maxi = *max_element( nums.begin() , nums.end());
        // int greater = 1;
        for( int i=mini; i>=1; i--)
        {
            if( mini%i==0 && maxi%i==0) return i;
        }
        return 1;
    }
};
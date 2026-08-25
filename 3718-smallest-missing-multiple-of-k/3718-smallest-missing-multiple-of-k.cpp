class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int next=1;
        unordered_set<int>look;
        for( int i=0; i<nums.size();i++)
        {
            if(nums[i]%k==0)
            {
                if(look.find(nums[i]) != look.end()) continue;
                if( nums[i]==next*k) { look.insert(nums[i]);next++;}
                else return next*k;
                
            }  
        }
        return next*k;
    }
};
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int next=1;
        // unordered_set<int>look;
        int previous=-1;
        for( int i=0; i<nums.size();i++)
        {
            if(nums[i]%k==0)
            {
                if(previous!=-1 && nums[i] == previous ) continue;
                if( nums[i]==next*k) { previous = next*k;next++;}
                else return next*k;
                
            }  
        }
        return next*k;
    }
};
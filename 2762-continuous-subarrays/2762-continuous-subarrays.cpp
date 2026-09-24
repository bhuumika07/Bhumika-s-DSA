class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque< int > maxis;
        deque< int > minis;
        int left = 0;
        int right = 0;
        long long ans = 0;
        while( right < nums.size())
        {
            while(!maxis.empty() && nums[maxis.back()] < nums[right]) maxis.pop_back();
            while( !minis.empty() && nums[minis.back()] > nums[right]) minis.pop_back();
            maxis.push_back(right);
            minis.push_back(right);
            int maxi = nums[maxis.front()];
            int mini = nums[minis.front()];

            while( abs(maxi-mini) > 2 && left <=right)
            {
                if( !maxis.empty() && maxis.front() == left) {
                    maxis.pop_front();
                    if(!maxis.empty()) maxi = nums[maxis.front()];
                }
                if(!minis.empty() && minis.front() == left)
                {
                    minis.pop_front();
                    if(!minis.empty()) mini = nums[minis.front()];
                }
                left++;
            }  
            if( abs(maxi - mini) <= 2) ans+=right-left+1; 
            right++;      
        }

        return ans;
        
    }
};
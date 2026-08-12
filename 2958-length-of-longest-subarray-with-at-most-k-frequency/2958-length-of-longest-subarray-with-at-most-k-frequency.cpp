class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        //need to track the highest frequency.
        unordered_map<int,int>mpp;
        int len=0;
        int maxlen=0;
        int left=0;
        int right=0;
        int maxfreq=0;
        while( right < nums.size())
        {
            mpp[nums[right]]++;
            maxfreq= max( maxfreq , mpp[nums[right]]);
            while( maxfreq > k)   
            {
                if(mpp[nums[left]] == maxfreq)
                {
                    mpp[nums[left]]--;
                    maxfreq=mpp[nums[left]];
                    left++;
                    len--;
                    break;
                }
                mpp[nums[left]]--;
                left++;
                len--;
            }

            if( maxfreq <= k) len++;
            maxlen=max(len,maxlen);
            right++;
        }
        return maxlen;
        
    }
};
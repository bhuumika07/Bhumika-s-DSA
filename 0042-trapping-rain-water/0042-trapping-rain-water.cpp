class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left;
        vector<int>right( height.size() , 0);
        int prev_max=0;
        for( int i=0; i< height.size(); i++)
        {
            left.push_back(prev_max);
            prev_max= max( height[i] , prev_max);
        }
        int next_max=0;
        for( int i= height.size()-1; i>=0; i--)
        {
            right[i] = next_max;
            next_max= max( height[i], next_max);
        }
        int count=0;
        for( int i=0; i< height.size(); i++)
        {
            int k = min( left[i] , right[i]) - height[i];
            if(k > 0) count+=k;
        }
        return count;
        
    }
};
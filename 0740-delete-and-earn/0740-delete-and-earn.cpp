class Solution {
public:
    
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int x: nums) freq[x]++;
        vector<int>temp;
        for(auto x:freq) temp.push_back(x.first);
        sort(temp.begin(), temp.end());
        if( temp.size() == 1) return temp[0]*freq[temp[0]];
        
        int secondLast = temp[0] * freq[temp[0]];
        int last=0;
        if(temp[0]+1 == temp[1]) last = max(secondLast, temp[1]*freq[temp[1]]);
        else last = secondLast + temp[1]*freq[temp[1]];
        int ans=max( last , secondLast);
        for(int i=2; i<temp.size();i++)
        {
            int val = temp[i]*freq[temp[i]];
            if(temp[i] != temp[i-1] + 1)
            {
                ans = max( last , secondLast) + val;
            }
            else
            {
                ans=max( last , val + secondLast);
            }
            secondLast =last;
            last=ans;
        }
        return ans;

    }
};
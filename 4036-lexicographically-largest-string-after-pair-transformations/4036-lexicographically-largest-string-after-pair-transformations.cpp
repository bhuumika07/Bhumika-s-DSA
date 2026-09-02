class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
      vector<long long>powers(26,1);
      int start = 1;
      powers[0]=start;
      for( int i=1; i<26; i++)
      {
        powers[i]=powers[i-1]*2;
      }
      vector<string>ans;
      for( int i=0; i<nums.size();i++)
      {
        int value = nums[i];
        string str="";
        while (value > 0) 
        {
             int idx = upper_bound(powers.begin(),powers.end(),
                    value
                ) - powers.begin() - 1;
                value -= powers[idx];
                str += ('a' + idx);
            }
        ans.push_back(str);
      }
      return ans;
        
    }
};
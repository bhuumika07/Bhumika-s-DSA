class Solution {
public:
    int dp[100005];
    int doit( vector<int>&temp , unordered_map<int,int>&freq, int idx)
    {
        if( idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];

        // take it
        int left = temp[idx] * freq[temp[idx]];
        if(idx-1 >= 0)
        {
            if(temp[idx-1] +1 == temp[idx])
            {
                if( idx -2 >=0  ) 
                    if (dp[idx-2] != -1)left+=dp[idx-2];
                    else left+=doit(temp,freq,idx-2);
            }
            else
            {
                if( dp[idx-1] != -1) left+=dp[idx-1];
                else left+=doit(temp,freq,idx-1);
            }
        }

        int right=0;
        if( idx >= 1)
        {
            right += temp[idx-1] * freq[temp[idx-1]];
            if( idx - 2 >= 0 )
            {
                if(temp[idx-1] == temp[idx-2]+1)
                {
                    if( idx-3 >=0 ) 
                        if( dp[idx-3] != -1)right+=dp[idx-3];
                        else right += doit(temp,freq,idx-3);
                }
                else
                {
                    if(dp[idx-2] != -1) right+=dp[idx-2];
                    else right+=doit(temp,freq,idx-2);
                }
            }
        }

        return dp[idx]= max(left, right);
    }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>freq;
        for( int x : nums) freq[x]++;
      
        vector<int>temp;
        for( auto x : freq)
        {
            temp.push_back(x.first);
        }
        sort(temp.begin() , temp.end());
        int size = temp.size();
        memset(dp, -1, sizeof(dp));
        return doit(temp,freq,size-1);

        
    }
};
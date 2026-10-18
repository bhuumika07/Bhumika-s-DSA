class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<long long>>cmbnts;
    long long solve( vector<int>&nums)
    {
        int n = nums.size();
        if( n <= 2) return 1;
        
        vector<int> left , right;
        int root = nums[0];
        for( int i = 1; i<n; i++)
        {
            if( nums[i] > root ) right.push_back( nums[i] );
            else left.push_back( nums[i]);
        }
        int L = left.size();
        int R = right.size();

        long long leftWays = solve( left );
        long long rightWays = solve( right );

        long long ways = cmbnts[L+R][L];

        return 1LL*ways*leftWays%mod*rightWays%mod;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        cmbnts.assign(n+1 , vector<long long>(n+1 , 0));
        for( int i = 0; i<=n ; i++)
        {
            cmbnts[i][0] = cmbnts[i][i] = 1;
            for( int j = 1; j<i; j++)
            {
                cmbnts[i][j] = (cmbnts[i-1][j-1] + cmbnts[i-1][j])%mod;
            }
        }
        return (solve(nums) - 1)%mod;
    }
};
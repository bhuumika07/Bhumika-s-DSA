class Solution {
public:
    long long dp[100005];
    long long doit( vector<vector<int>>&questions , long long idx )
    {
        if( idx >= questions.size()) return 0;
        long long skip = 0;
        if(idx+1 < questions.size() && dp[idx+1] != -1) skip = dp[idx+1];
        else skip = doit(questions , idx+1);
       
        long long val = questions[idx][0];
        long long jump = questions[idx][1];

        long long take = val ;
        if( idx+jump+1 < questions.size()) 
            if(dp[idx+jump+1] !=-1 ) take+=dp[idx+jump+1];
            else take+=doit(questions , idx+jump+1);


        return dp[idx]=max(skip,take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset( dp , -1 , sizeof(dp));
        return doit(questions , 0);
    }
};
class Solution {
public:
    int dp[1001][201];
    int doit(vector<int>&prices , int buysLeft ,  int index){
        if(index >= prices.size() || buysLeft == 0) return 0;
        if(dp[index][buysLeft] != -1) return dp[index][buysLeft];
        int profit = 0;
        if(buysLeft % 2 == 0){
            profit = max(-1*prices[index] + doit(prices, buysLeft-1, index+1) , doit(prices , buysLeft , index+1));
        }
        else{
            profit = max(prices[index] + doit(prices ,buysLeft - 1 , index+1) , doit(prices , buysLeft , index+1));
        }
        return dp[index][buysLeft] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        // to write tabulation
        int n = prices.size();
        int buys = k*2;
        vector<vector<int>>dp(n+1 , vector<int>(buys+2,0) );
        for( int index = n-1; index >= 0; index--){
            for( int buysLeft = buys; buysLeft >= 1; buysLeft--){
                int profit = 0;
                if(buysLeft % 2 != 0){
                profit = max(-1*prices[index] + dp[index+1][buysLeft+1],dp[index+1][buysLeft]);
                }
                else{
                profit = max(prices[index] +dp[index+1][buysLeft+1],dp[index+1][buysLeft]);
                }   
                dp[index][buysLeft] = profit;
            }

        }
        return dp[0][1];
    }
};
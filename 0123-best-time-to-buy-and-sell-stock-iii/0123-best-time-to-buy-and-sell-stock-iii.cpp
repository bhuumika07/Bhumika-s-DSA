class Solution {
public:
    int dp[100001][2][5];
    int doit( vector<int>&prices , int index , int left , bool buy){
        if( left== 0) return 0;
        if( index >= prices.size()) return 0;
        if(dp[index][buy][left] != -1) return dp[index][buy][left];
        int profit = 0;
        if( buy ){
            profit = max( -1 * prices[index] + doit(prices , index+1 , left - 1, 0 ) , doit(prices , index+1 , left , 1));
        }
        else{
            // need to sell.
            profit = max( prices[index] + doit(prices , index+1 , left-1,1) , doit(prices , index+1 , left , 0));
        }
        return dp[index][buy][left] = profit;

    }
    int maxProfit(vector<int>& prices) {
        // func( arr , index , count , buy);
        memset(dp,-1,sizeof(dp));
        return doit(prices , 0 , 2*2 , 1);
    }
};
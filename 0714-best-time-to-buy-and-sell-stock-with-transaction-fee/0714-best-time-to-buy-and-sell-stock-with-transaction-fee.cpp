class Solution {
public:
    int dp[50005][2];
    int doit( vector<int>&prices , int index , int fee , bool buy){
        if(index >= prices.size())  return 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        int profit = 0;
        if(buy){
            profit = max(-1*prices[index] + doit(prices , index+1 , fee , 0), doit(prices , index+1 , fee, 1));
        }
        else{
            profit = max(prices[index] - fee + doit(prices , index+1 , fee , 1) , doit(prices , index+1 , fee , 0));
        }
        return dp[index][buy] = profit;

    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return doit(prices , 0, fee , 1);
    }
};
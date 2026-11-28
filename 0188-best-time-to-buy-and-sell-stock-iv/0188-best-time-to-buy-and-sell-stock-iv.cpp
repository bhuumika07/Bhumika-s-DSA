class Solution {
public:
    int dp[1001][101][2];
    int doit(vector<int>&prices , int left , int buy, int index){
        if(index >= prices.size() || left == 0) return 0;
        if(dp[index][left][buy] != -1) return dp[index][left][buy];
        int profit = 0;
        if(buy){
            profit = max(-1*prices[index] + doit(prices, left , 0 , index+1) , doit(prices , left , 1 , index+1));
        }
        else{
            profit = max(prices[index] + doit(prices , left -1 , 1 , index+1) , doit(prices , left , 0 , index+1));
        }
        return dp[index][left][buy] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
       return doit(prices , k , 1 , 0); 
    }
};